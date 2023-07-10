#include <sys/stat.h>
#include <sys/unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <string.h>
#include <sys/sem.h>
#include <errno.h>
#include <time.h>


int main()
{
    int sem_id;      /* a szemafor tomb id-je */
    key_t key;
    pid_t pid;


  /* struktura: hanyadik szemafor, muvelet, flag=0 vagy IPC_NOWAIT vagy SEM_UNDO*/
    struct sembuf down = {0, -1, 0};
    struct sembuf up = {0, 1, 0};
    struct sembuf down1 = {1, -1, 0};
    struct sembuf up1 = {1, 1, 0};

    key = ftok(".",'a');

    if ((sem_id = semget(key, 2,  IPC_CREAT | 0660 )) == -1 ) {
        perror("semget");
        exit(1);
    }

    /* beallitom a 0-as szemafor kezdoerteket 0 ra az 1-est 1-re */
    if (semctl (sem_id, 0, SETVAL, 0) == -1 || semctl (sem_id, 1, SETVAL, 1) == -1    ){
        perror("semctl");
    }


    pid = fork();
    if (pid <0){
        perror("fork");
        exit(1);
    }


     if (pid == 0){                  /*a fiu folyamat */
      sleep(5);
        if( semop (sem_id, &down1, 1 )<0) /* probalkozas elsore ez elvileg sikeres kell legyen*/
            perror("down1");
        printf("A fiu az elso aki belep a kritikus szekcioba!\n");    /* kritikus resz */
        if( semop (sem_id, &up, 1 )<0) /* probalkozas*/
            perror("up");
        exit(0);
      }

        if( semop (sem_id, &down, 1 )<0) /* probalkozas*/
            perror("down");
        printf("Az apa a masodik aki belep a kritikus szekcioba\n");
        if( semop (sem_id, &up1, 1 )<0) /* probalkozas*/
            perror("up1");




       wait(NULL);
  /* az apaban torlom a szemafort: ha eloszor a fiu tikk-el, akkor az apa utoljara*/
     if ( semctl (sem_id, 0,  IPC_RMID,0) < 0)   /* torlom a szemafort */
            perror("semctl");



    return 0;
}
