#include "myinclude.h"

int main(){

	int semid; //szemafor azonosito
	key_t key; //azonosito kulcs

	struct sembuf down0 = {0,-1,0};
	struct sembuf up0 = {0,1,0};

	struct sembuf down1 = {1,-1,0};
	struct sembuf up1 = {1,1,0};


	key=ftok("/usr/bin",25);

	if((semid=semget(key,2,IPC_CREAT|0660))<0)
		syserr("szemafor creat");

	if(semctl(semid,0,SETVAL,1)==-1 || semctl(semid,1,SETVAL,0)==-1)
		syserr("szemafor init");





exit(0);
}
