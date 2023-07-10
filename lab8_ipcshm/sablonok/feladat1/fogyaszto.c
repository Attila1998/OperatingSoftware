//olvasó folyamat

#include "myinclude.h"
#include "shm.h"

//két szemafort használunk
//kezdőérték s0=1, s1=0
//az olvasó folyamat down: -1->s1
//                   up:   +1->s0

int main( int argc, char * argv[])
{
    int semid, shmid;
    char * mem;    //ide csatoljuk 
	char * shmp;  

    //TODO: szemafor műveletek definiálása
	
	struct sembuf down = {0, -1, 0};
	struct sembuf up = {1, 1, 0};
                  
    //TODO: szemafor tömb lekérése

    if((semid=semget(key,2,IPC_CREAT|0660))<0)
	syserr("szemafor");

    if((shmid=shmget(key,sizeof(int),0660 | IPC_CREAT))<0)
	syserr("memoria");

    //TODO: osztott memória id lekérése

	shmp = (char*) shmget ( shmid, NULL, 0);

    //TODO: osztott memória felcsatolása
	mem = (char*) shmat ( shmp, NULL, 0);

    while(1) {

    //TODO:
    // 1. down művelet
	
		if(semop(semid,&down,1)<0)
		syserr("semdown");
	
    // 2. 1 sor olvasása és kiírása: mem->stdout 
    printf("%s",mem);
    // 3. up művelet
	
	    if(semop(semid,&up,1)<0)
        syserr("semdown");
	
    //ha  a sor "exit" akkor break

    }    

    //TODO: osztott memória lecsatolás
	if (shmdt( (void*) shmp ) < 0){
		syserr("shmdt");

    //TODO: szemafor tömb és osztott memória id törlése
    if(semctl(semid,0,IPC_RMID)<0) syserr("ctl1"); 
    if(shmctl(shmid,IPC_RMID,0)<0) syserr("ctl2"); 



    exit(EXIT_SUCCESS);
}