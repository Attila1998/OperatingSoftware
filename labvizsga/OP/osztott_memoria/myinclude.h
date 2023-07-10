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


extern int errno;

//hibakezelo fuggveny a rendszerhivasokhoz
void syserr ( char * msg )  

{  
    printf ("rendszer hiba: %s\n", msg); 
    perror("");
    exit (1); 
}  

//ugyananaz makroval megoldva

#define ERROR(message)  { perror (message); exit(1);}

