/*
  feladat 1 sablon f2.c
*/
#include "myinclude.h"
#include "f12.h"

int main( int argc, char * argv[])
{
    int semid; //szemafor tömb 
    int shmid;
    key_t key;
    char * shmp;
    int * valt;
    key=ftok(FTOK_FILE,FTOK_ID);


    //TODO:a két szemafor művelet f2 számára
	struct sembuf down = {1, -1, 0};
	struct sembuf up = {0, 1, 0};

    //TODO: a szemafor tömb lekérése, adjon hibát ha nem létezik
    if((semid=semget(key,2,0))<0)
		syserr("szemafor");

    if((shmid=shmget(key,sizeof(int),0660 | IPC_CREAT))<0)
	syserr("memoria");

    shmp = (char *) shmat(shmid,NULL,0); //csatolom a memoria szegmenst
	if(shmp==(void *)-1)
		syserr("shmat");
    valt=(int*)shmp;



        //TODO: kritikus szakaszba lép
        if(semop(semid,&down,1)<0)
		syserr("semdown");

        //kritikus szakasz
	printf("a valtozok erteke: %i\n",*valt);

        //TODO:kilép a kritikus szakaszból
	if(semop(semid,&up,1)<0)
		syserr("semdown");

	if(shmdt((void*)shmp)<0)
		syserr("shmdt");


    exit(EXIT_SUCCESS);

} 
