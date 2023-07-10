#include <sys/stat.h>  
#include <sys/unistd.h>  
#include <sys/types.h>
#include <fcntl.h>  
#include <stdlib.h>  
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>  
#include <string.h>
#include <errno.h>

 
extern int errno ; /* az errno.h által visszadott hibakód */

//rendszer hiba kiíró függvény
//egy sztringet kap bemenetként, kiírja a sztringet és
//hozzáfűzi a rendszer hiba üzenetét:
//   msg : rendszerhiba
//   alakban
void syserr ( const char * msg )  
{  
    perror ( msg ); /* kiírja az errno változóban található hibakódot
                    és egy rövid hiba üzenetet */
    exit (errno); 
}  

