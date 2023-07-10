/* 
 * Sablon: Labor 3, feladat 7.
 *
 * futtatás méréshez:
 *
 * ./kiazelso 100000
 *
 */

#include "myinclude.h"

int main(int argc, char *argv[])
{
    int fd;
    pid_t pid; 
    long long ciklus,i;

    //ezt a két változót írjuk a fájlba
    char one[] = "1\n";
    char zero[] = "0\n";

    setbuf  (stdout,NULL);

    //TODO: ha nincs parancssori paraméter, ciklus=1000,
    //ha van, akkor atoll() függvénnyel átalakítjuk
    //és beírjuk a ciklus-ba
    //ha 0-t kapunk hiba és kilépünk


    //TODO: megnyitjuk ki.txt fájlt írásra, csonkolás, új fájl
    

    //TODO: ellenőrzés, megnyilt-e a fájl


    //elvégezzük többször a kiírásokat
    for (i=0; i<ciklus;i++)
    {

        //TODO: új folyamat, pid szám a pid változóba
        //ellenőrzés, hogy sikerült

        //fiú:
        if (pid == 0){

            //TODO: beírja a zero változó tartalmát a fájlba, 2 karaktert
            
            exit(0);
        }else
        { //apa:
            
            //TODO: beírja a one változó tartalmát a fájlba, 2 karaktert


            //TODO: apa megvárja a fiát

        }
    }
    exit(EXIT_SUCCESS);
}      
