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

	//belepek a kritikus szekcioba
	if(semop(semid,&down0,1)<0)
		syserr("semop");
	
	//kritikus szekcio
	printf("szem2.c kritikus reszben\n");

	if(semop(semid,&up1,1)<0)
		syserr("semop");
	//kileptem a kritikus szekciobol




exit(0);
}
