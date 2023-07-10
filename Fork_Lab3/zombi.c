/*
 * Zombi processz pelda
 * inditsuk el a programot:
 *
 *      gcc zombi.c -o zombi 
 *      zombi &
 * 
 * utana: nezzuk meg tobbszor egymas utan az alabbi ps paranccsal:
 * 
 * ps -o pid,ppid,stat,command
 * 
 */

#include "myinclude.h"

int main()
{
    pid_t child;
    int child_allapot;

    child = fork();

    if (child < 0) {
        syserr("fork");
    }

    if (child == 0) { //fiu folyamat
        exit (0);   
        /* a fiu azonnal kilep, mivel az apa var, a fiu 
         * ettol a pillanattol kezdve zombi */
    }

    sleep(60); //apa var 
    /* 60 szek mulva er ide az apa, addig a fiu zombi */

    wait (&child_allapot);
    /* a wait fogadta a fiu befejezesi kodjat - termination status
     * ekkor a zombinak el kell tunnie
     */
    printf("Apa alszik\n");	
    sleep (20);
    /* itt meg var 30 szekundomot, megnezhetjuk, hogy a zombi eltunt */
    printf("Apa felébredt\n");	

    printf ("\nVége.\n");
    exit(0);
}	
