/* 
 * nagyon egyszeru kommunikacio ket folyamat kozott:
 *
 * a message nevu file jelenlete jelzi a fiu folyamatnak,
 * hogy az apa befejezett  egy feladatot es o kovetkezik
 * amig nincs message nevu fajl, a fiu var
 */

#include "myinclude.h"

int main() {

    pid_t fiu_pid ;
    int fd;

    setbuf(stdout,NULL);

    //mi tortenik ha masodszor futtatjuk a programot
    //es kivesszuk az unlink() hivast?
    if ( ! access("message",F_OK) ) { //letezik a fajl?
        printf("torles\n");

        if ( unlink ("message") < 0 ){ /* torljuk  a message  nevu allomanyt*/
            syserr("nem lehet törölni a message nevű fájlt\n"); 
        }
    }

    fiu_pid = fork();

    if (fiu_pid < 0) {
        syserr("fork");
    } 
    if ( fiu_pid == 0) {
        /* fiu var addig, amig megjelenik a file */
        while ( access("message", F_OK ) == -1){
            usleep(100000); // az usleep-nek mikroszekundumban adjuk meg a varakozasi idot
            //100000 * 1 us = 100msec
        }
        printf ("fiú: message megjött\n");
        sleep(1); 
        printf ("fiú kilép\n");
        exit(0);    /* a fiu itt kilep */
    }
    //apa kódja
    printf ("Pid számok, apa=%d fiú=%d\n", getpid(), fiu_pid);
    /* apa folyamat kiir kis varakozassal*/
    printf("apa: vár\n");
    sleep(3); //hosszabb idot var

    printf("apa: message létrejön\n");
    /* itt letrehozza a message allomanyt */
    if ( (fd=open("message", O_CREAT | O_WRONLY | O_TRUNC, 0644))<0){
        syserr("open message");
    }
    close(fd);
    wait(NULL);  //megvarja a fiat
    printf("apa: kilép\n");
    exit (0);
}

