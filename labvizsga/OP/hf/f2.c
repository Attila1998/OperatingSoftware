/*
  feladat 1 sablon f2.c
*/
#include "myinclude.h"
#include "f12.h"

int main( int argc, char * argv[])
{
    int semid; //szemafor tömb 
    int fid;  //fájl
    char b  = 'b'; //ezt írjuk a fájlba
    int count = N; //számláló
    key_t key;

    key=ftok(FTOK_FILE,FTOK_ID);


    //TODO:a két szemafor művelet f2 számára
	struct sembuf down = {1, -1, 0};
	struct sembuf up = {0, 1, 0};

    //TODO: a szemafor tömb lekérése, adjon hibát ha nem létezik
    if((semid=semget(key,2,0))<0)
		syserr("szemafor");

    //TODO: fájl nyitása írásra, adjon hibát ha nem létezik
    if((fid=open(FNAME,O_WRONLY| O_APPEND))<0)
		syserr("file nyitas");

    //íro ciklus
    while (count--)
    {
        //TODO: kritikus szakaszba lép
        if(semop(semid,&down,1)<0)
		syserr("semdown");

        //TODO: ír
	if(write(fid,&b,1)<1)
		syserr("write");

        //TODO:kilép a kritikus szakaszból
	if(semop(semid,&up,1)<0)
		syserr("semdown");
    }

    //TODO: törli a szemafor tömböt
    //ez a folyamat használja utoljára
    if ( semctl (semid, 0, IPC_RMID,0) < 0)
		syserr("szem torles");


    //zárja a fájlt
    close(fid);
    exit(EXIT_SUCCESS);

} 
