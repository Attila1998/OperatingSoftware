/* 
 * pelda az execvp hasznalatara 
 * egyszerubb az argv eloallitas, mint az execvp.c-ben
 * viszont korlatozzuk a hosszat
 * */

#include "myinclude.h"

#define MAX_ARGS 128

//a parancssort feldolgozo fuggveny
//bemenet: parancssor sztring, pl:
//   ls -l /home
//kimenet: hibakod, ha nem hajtodik végre a parancs   
int parancssor ( char * parancs)
{
    char * argv[MAX_ARGS] ; //ebben lesz az argv
    char * s;
    int argc = 0; 
    char ** ptr = argv;   //mutató az argv-re

    s = strtok(parancs, " "); //elso sztring

    while ( s != NULL ){

        *ptr++ = s;            //mutato bekerul az argv-be
                               //s sztring marad a helyen
        s = strtok(NULL, " "); //kovetkezo sztringek
        
        //ellenorzes, hogy ne lepjem tul a MAX_ARGS-ot
        if (++argc >= MAX_ARGS){
            fprintf(stderr, "túl sok argumentum\n");
            return 1;      
        }
    }
    *ptr = NULL ; //argv tömb lezárása
    // itt megvan az argv 
    execvp (argv[0], argv);
    // ide akkor jutunk ha nem sikerul 
    return 1;
} 

#define MAX 256  //egy parancssor hossza

int main (int argc, char * argv[])
{
    pid_t pid;
    int status;
    char parancs[MAX];

    setbuf(stdout,NULL);

    /* parancssor beolvasasa: */
    printf("írjunk be egy parancsot(például: ls -l /home ):");
    if ( fgets (parancs, MAX, stdin) == NULL){    /*olvasas stdin-rol*/
        fprintf(stderr,"olvasas hiba\n");
        exit(EXIT_FAILURE);
    }

    //az fgets altal beolvasott sztring vegen
    //van egy ujsor, azt felulirjuk
    parancs[strlen(parancs)-1]='\0';

    pid = fork();
    if ( pid < 0){
        syserr("fork");
    }

    if ( pid == 0){

        /* fiu folyamat, uj programot inditunk */
        parancssor(parancs);

        /* ide mar nem ter vissza */
        syserr ("execv hiba\n");
    } 


    /*apa folyamat megvarja a fiut */
    wait (&status);
    exit(EXIT_SUCCESS);

}
