
/* osztott memoria hasznalata 
 * az apa es fiu follyamatok felvaltva
 * novelik egy valtozo erteket az osztott memoriaban
 *
 * minden ciklusban ellenorzik, hogy a szam paros vagy paratlan
 * az egyik paros a masik mindig paratlan szamokat kell
 * ott talaljon
 *
 * az ilyen muveleteket szinkronizalni kell szemaforral
*/

#include "myinclude.h"


int main()
{
    int shm_id;    /* osztott mem */
    int sem_id;    /* szemafor */
    
    char * shmem ; /* ez a mutato mutat az osztott memoriara, !!! char* */    
    int * ip;      /* ez pedig a hasznalt adattipusra mutat */

	key_t key;

    //a negy muvelet alternalo mukodeshez
    struct sembuf up = {0, 1, 0};
    struct sembuf down = {0, -1, 0};
    struct sembuf up1 = {1, 1, 0};
    struct sembuf down1 = {1, -1, 0};

    pid_t pid;     

	key=ftok("/bin",'a');


    /* osztott memoria 2 int valtozonak */
    if ( (shm_id = shmget (key, 2 * sizeof(int), 0660 | IPC_CREAT)) == -1) 
        syserr("shmget");
    /* 2 szemaforbol allo tomb id-je */            
    if ( (sem_id = semget (key, 2, 0660 | IPC_CREAT)) == -1)
        syserr("semget") ;   
                
    if ( semctl( sem_id, 0, SETVAL, 1) < 0)  /* a ket szemafor beallitasa 0/1 */
        syserr("semctl");
    if ( semctl( sem_id, 1, SETVAL, 0) < 0)
        syserr("semctl");
    

    if ( (shmem = ( char* ) shmat ( shm_id, 0, 0)) == (void*) -1)  /* attach */        
        syserr ("shmat");
                
    // az int mutato hozzarendelese az osztott memoriahoz 
    // lehetne ezt egybol hasznalni a shmat() hivasban
    // de jobb ha marad egy char * ami biztosan az osztottra mutat
    ip = (int*) shmem;
    
    *ip = 0; /*kezdoertek, paros szam,eloszor a fiu fogja modositani */

    pid = fork();
    if (pid < 0) 
           syserr("fork");

    if (pid == 0){
                
       
            if ( semop (sem_id, &down, 1) < 0)  
                syserr("semop 0");


            (*ip) = 2466776; /* osztott memoriaban levo ertek */


            if ( semop (sem_id, &up1, 1) < 0)  
                   syserr("semop 1")  ;  

        
        /* vege: a fiu detach muveletet vegez es kilep */
        if ( shmdt ( shmem ) < 0) 
              syserr("shmdt"); /* detach */

        exit(0);

     }else
     {    /* az apa kodja */
      
        
            if ( semop (sem_id, &down1, 1) < 0)  
                 syserr("semop 1");
        
            printf("%i\n",*ip); /*kiirom az osztott memoriaban levo valtozo erteket */

            if ( semop (sem_id, &up, 1) < 0)  syserr("semop 0");        
        
        
     }
   
    //levalasszuk a memoriat 
    if ( shmdt ( shmem ) < 0) syserr("shmdt");
      
    wait(NULL);
    /* vege 
        toroljuk  az OPC objektumokat */  
    if ( shmctl ( shm_id , IPC_RMID, 0) <0 )  syserr("shmctl");
    if ( semctl ( sem_id , 0, IPC_RMID) <0 )  syserr("shmctl");        

    exit(0);    
                
}    


