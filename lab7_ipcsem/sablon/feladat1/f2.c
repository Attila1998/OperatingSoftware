/*
  feladat 1 sablon f2.c
*/
#include "myinclude.h"
#include "f12.h"

int main( int argc, char * argv[])
{
    int semid; //szemafor tömb 
    int fid;  //fájl
    char b  = 'b'; //ezt írjuk a fájlba
    int count = N; //számláló

    //TODO:a két szemafor művelet f2 számára
    //struct sembuf ... 
    //struct sembuf ...

    //TODO: a szemafor tömb lekérése, adjon hibát ha nem létezik
    //az f1 által létrehozva

    //TODO: fájl nyitása írásra, adjon hibát ha nem létezik
    //ne csonkolja

    //íro ciklus
    while (count--)
    {
        //TODO: kritikus szakaszba lép

        //TODO: lseek

        //TODO: ír

        //TODO:kilép a kritikus szakaszból

    }

    //TODO: törli a szemafor tömböt
    //ez a folyamat használja utoljára

    //zárja a fájlt
    close(fid);
    exit(EXIT_SUCCESS);

} 