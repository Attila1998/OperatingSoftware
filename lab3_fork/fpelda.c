/* egyszeru fork pelda */

#include "myinclude.h"

int main() {
    int i;

    pid_t fiu_pid ;
    pid_t apa_pid ;

    fiu_pid = fork();
    if (fiu_pid < 0) {
        syserr("fork");
    } 

    if ( fiu_pid == 0) {
        /* erre a kod reszre csak a fiu processz lep ra*/
        apa_pid = getppid();
        i=2;
        printf ("fiú a fork után i=%d ,apa pid= %d, fiú  pid = %d\n",\
                i, apa_pid, (int) getpid());
        exit(0);	/* a fiu itt kilep */
    }
    else 
    {	
        /* erre a kodreszre csak az apa */	 
        i=6;
        sleep(3);  /* 3 masodpercet var: igy valoszinu, hogy a fiu hamarabb
                      fejezodik be */
        /* ez nem helyes, ilyenkor kell a wait fuggvenyt hasznalni 
         * semmi sem garantalja, hogy a fiu eddig lefut */
        printf("apa a fork után: i=%d a fiú pid: %d\n",i, (int) fiu_pid);
    }

    /* ide mar csak az apa jut el */
    exit (0);
}
