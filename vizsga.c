#include "myinclude.h"


int main(int argc, char *argv[]){

//valtozo inicializalas

static int semid, shmid;  //szemafor, osztott mmeoria id
static char * mem;       //szegmens kezdo cime
void *shmem; // erre a mutatora csatoljuk az osztott memoriat
pid_t pid1;
pid_t pid2;
pid_t pid3;
int szam;


    // osztott memoria 1 int valtozonak
    if ((shmid = shmget(IPC_PRIVATE, sizeof(int), 0660 | IPC_CREAT)) < 0)
        syserr("shmget");

    // 2 szemaforbol allo tomb id-je
    if ((semid = semget(IPC_PRIVATE, 3, 0660)) < 0)
        syserr("semget");

    if (semctl(semid, 0, SETALL, init) < 0) 
        syserr("semctl");


	if (shmdt((void*) mem)>0) syserr("csatolas");
	
    if ((sem_id = semget(IPC_PRIVATE, 3, IPC_CREAT | 0660)) == -1)
    {
        syserr("semget");
    }

//kulcs : /bin/bash 36
key_t key=frok("/bin/bash",36)
//uzenet char tomb merete 50 karakter

char uzenet=(char*)calloc(50,sizeof(char));
int paros,charnum;



//system v eroforrassok inicializalasa


//folyamatok letrehozasa

    pid = fork();
    if (pid < 0)
    {
        printf("\nfork hiba");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0)
    { //a fiu folyamat ciklusa 
        {
            if (semop(sem_id, &paros, 1) < 0) // probalkozas
                syserr("down1");
        }
	scanf("%c ";uzenet);
        exit(0);
    }

    if (pid2 == 0)
    { //a fiu folyamat ciklusa 
        {
            if (semop(sem_id, &uzenet, 1) < 0) // probalkozas
                syserr("down1");
        }

    shmem = shmat(shmid, NULL, 0); // attach

    if (shmem == (void *)-1)       
        syserr("shmat");

	for(int i=0;i<strlen(char);i++)
	szam++;
	
*enum=szam;
if(szam%2==0){*paros=1;}
	else{*paros=;
        if (shmdt(shmem) < 0)
            syserr("shmdt"); // detach

        exit(0);
    }

    if (pid3 == 0)
    { //a fiu folyamat ciklusa 

    shmem = shmat(shmid, NULL, 0); // attach

    if (shmem == (void *)-1)       
        syserr("shmat");
	if(*paros==1){printf("%i ",charnum);}
        if (shmdt(shmem) < 0)
            syserr("shmdt"); // detach

        exit(0);
    }

//folyamatok befejeztenek megvarasa

    wait(&pid1);
    wait(&pid2);
    wait(&pid3);

//system v eroforrasok torlese

    if (shmctl(shmid, IPC_RMID, 0) < 0)
        syserr("shmctl");
    if (semctl(semid, 0, IPC_RMID, 0) < 0)
        syserr("shmctl");

exit(0);
}
