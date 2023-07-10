/*
  feladat 1 sablon f1.c
*/

#include "myinclude.h"
#include "f12.h"

int main(int argc, char *argv[])
{
    int semid;     //szemafor tömb
    int shmid;
    key_t key;
    char * shmp;  //ide mentjuk osztott memoria szegmens kezdo cime
    int * valtozo; //az osztott memoriaban levo valtozo
    int * valtozo2;
    char * x;

    key=ftok(FTOK_FILE,FTOK_ID);	
    

    //TODO: a két művelet f1 számára
	struct sembuf down = {0, -1, 0};
	struct sembuf up = {1, 1, 0};

    //TODO: szemafor tömb lekérés, hozza létre ha nem létezik
    if((semid=semget(key,2,IPC_CREAT|0660))<0)
	syserr("szemafor");

    if((shmid=shmget(key,9,0660 | IPC_CREAT))<0)
	syserr("memoria");

    shmp = (char *) shmat(shmid,NULL,0); //csatolom a memoria szegmenst
	if(shmp==(void *)-1)
		syserr("shmat");

    valtozo=(int*)shmp;
    valtozo2=(int*)shmp+4;
    x=(char*)shmp+8;

    //TODO: szemafor tömb inicializálás
 if(semctl(semid, 0, SETVAL, 1) == -1 || semctl(semid, 1, SETVAL, 0) == -1)
	syserr("szemafor beallitas");



        //TODO: kritikus szakaszba lép
	if(semop(semid,&down,1)<0)
		syserr("semdown");

	sleep(60);
        //kritikus szakasz
	*valtozo=3456789;


        //kilép a kritikus szakaszból
        if(semop(semid,&up,1)<0)
                syserr("semdown");

	if(shmdt((void*)shmp)<0)
		syserr("shmdt");
    exit(0);
}
