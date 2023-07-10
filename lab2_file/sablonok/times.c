/* 
 * FELADAT: kiírja, hányszor van meg egy karakter egy fájlban
 * futtatás:
 *     ./times a.txt a
 */

#include "myinclude.h"

#define BUFFSIZE 128 
int main(int argc, char * argv[])
{

    char buff[BUFFSIZE]; //ebbe olvasunk
    int fd; //fájl azonosító
    int count;

    //TODO: mennyi az argc
    if (argc ... ) {
        printf("használat: %s fájlnév karakter\n", argv[0]);
        exit(EXIT_FAILURE);
    }


    //fájl nyitás olvasásra és hiba ellenőrzés

    count=0;
    int n; 

    //TODO: a read paramétereit megadni
    while ( (n=read( ... )) ) {
        if (n<0){
            syserr("read");
        }
        //TODO: karaktereket számolni
    }

    printf("%d\n", count);

    if (close(fd)<0){
        syserr("close");
    }

    exit(EXIT_SUCCESS);
}

