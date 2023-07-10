/*
  feladat 1 sablon f1.c
*/

#include "myinclude.h"
#include "f12.h"

int main(int argc, char *argv[])
{
    int semid;     //szemafor tömb
    int fid;       //fájl
    char a = 'a';  //ezt írjuk a fájlba
    int count = N; //számláló
    key_t key;

    key=ftok(FTOK_FILE,FTOK_ID);	
    

    //TODO: a két művelet f1 számára
	struct sembuf down = {0, -1, 0};
	struct sembuf up = {1, 1, 0};

    //TODO: szemafor tömb lekérés, hozza létre ha nem létezik
    if((semid=semget(key,2,IPC_CREAT|0660))<0)
	syserr("szemafor");


    //TODO: szemafor tömb inicializálás
 if(semctl(semid, 0, SETVAL, 1) == -1 || semctl(semid, 1, SETVAL, 0) == -1)
	syserr("szemafor beallitas");


    //TODO: fájl megnyitása írásra, O_WRONLY | O_TRUNC | O_CREAT

    if((fid=open(FNAME,O_WRONLY | O_TRUNC | O_CREAT |O_APPEND ,0660))<0)
	syserr("fajlnyitas");




    //íro ciklus
    while (count--)
    {
        //TODO: kritikus szakaszba lép
	if(semop(semid,&down,1)<0)
		syserr("semdown");


        //TODO: ír
	if(write(fid,&a,1)<1)
		syserr("write");

        //kilép a kritikus szakaszból
        if(semop(semid,&up,1)<0)
                syserr("semdown");

    }

    //zárja a fájlt
    close(fid);

    exit(0);
}
