/* 
 * 
 * tobb szintu folyamat inditas, minden fiu folyamat uj fiut indit vizesesszeruen
 * a melyseg szama implicit 3, vagy megadhato a parancssoron
 *
 *   gcc -Wall cascade1.c -o cascade1
 *   ./cascade1 10
 */

#include "myinclude.h"

#define MAXCHILD 128  //maximalis melyseg
//ennel tobbet ne, mert blokkolni fogjak a rendszert

int main(int argc, char * argv[])
{

    pid_t pid, wpid;
    int n = 3; /* 3 ciklus implicit, ha nincs parameter */
    int i;

    setbuf(stdout,NULL);  // stdout: nincs puffereles 

    if (argc>1){
        n=atoi(argv[1]); //milyen melysegben inditsanak folyamatokat
    }

    if ( n < 1 || n > MAXCHILD){  //fiu szam nem tobb mint 256
        fprintf(stderr, "n 1..%d közötti, de aki szórakozni akar megnövelheti a MAXCHILD paramétert\n",MAXCHILD); exit(1);
    } 

    //fiu folyamatok inditasa
    for (i=0; i<=n; i++) {
        pid=fork();
        if (pid<0){
            syserr("fork hiba");
        }
        if ( pid == 0 ) {
            // a fiu folyamat vissza megy a for-ra es ismet indit egyet 
            //usleep(100000); //ha lassabban akarjuk futtatni  
            printf ("%d feladata elvégezve\n",getpid());
        }else
        {
            /* az apa bevarja fiat, nem megy vissza a for-ra
             * az exit() miatt 
             * */
            wpid=wait(NULL);
            printf ("%d megvárta %d-t és kilépett\n",getpid(),wpid);
            exit(0);
        }
    }

    /* az utolso fiu jut ide */
    printf ("%d utolsó fiú vege\n", getpid());
    exit(0);

}      

