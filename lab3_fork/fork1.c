/*
 * HIBÁS !!!  
 *
 * fork() mukodes ha a fork visszateritett erteke nincs lekezelve
 * !!! hibas programkod
 *
 * ha eleg nagyra noveljuk az i-t a ciklusban, vagy vegtelen ciklust  
 * irunk, akkor lefagyaszthatjuk vele a rendszert, lasd:
 * https://en.wikipedia.org/wiki/Fork_bomb
 *
 * Kerdes: hanyszor hajtodik vegre a fork() utani printf
 * es mi jelenik meg az stdout-on inditas utan ?
 */

#include <sys/types.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int i;

    printf("\naz indító shell PID száma: %d", (int) getppid());

    setbuf(stdout,NULL);  //az stdout-ra valo iraskor nincs puffer
    //tehat amit kuldok azonnal megjelenik

    for (i=0; i < 2; i++) { //ket ciklus, hany folyamat?

        fork();

        printf("\nPID=%d, PPID=%d, fork után az i értéke i=%d",
                (int) getpid(),(int) getppid() ,  i);

        sleep(1);  //1 masodpercet var
    }

    printf("\n");
    exit (0);
}
