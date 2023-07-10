#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
#include <sys/msg.h>

#include <wait.h>

#define SIZE     128 

typedef struct msgbuf {
         long    mtype;
         char   mtext[SIZE];
         } message_buf;

int main()
{
    int msqid;                      
    int msgflg = IPC_CREAT | 0660;    
    message_buf sbuf;
    key_t key;

    key = ftok(".",'a');

    if ((msqid = msgget(key, msgflg )) < 0) {
        perror("msgget");
        exit(1);
    }

   if ( msgrcv ( msqid, &sbuf, SIZE, 1,0 ) == -1 ) {
        perror("msgrcv");
        exit(1);
   }
   printf("%s", sbuf.mtext);

   if ( msgctl ( msqid, IPC_RMID, NULL ) < 0 ){
           perror ("msgctl");
           exit(1);
     }


    return 0;
}
