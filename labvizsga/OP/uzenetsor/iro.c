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
    size_t buf_length;

    key = ftok(".",'a');

    if ((msqid = msgget(key, msgflg )) < 0) {
        perror("msgget");
        exit(1);
    }

    (void) strcpy(sbuf.mtext, "Hello uzenet test!");
    buf_length = strlen (sbuf.mtext) + 1 ;
    sbuf.mtype=1;

    if (msgsnd(msqid, &sbuf, buf_length, 0) < 0) {
        perror("msgsnd");
        exit(1);
    }

    return 0;
}

