#include "myinclude.h"
#include "file.h"

int main( int argc, char * argv[])
{
    int semid;

    int fid; //fájl azonosító
    int cnt=0; //ciklus számláló
    char fname[] = "a.dat";

    //egy szemafor, kezdőértéke 0
    struct sembuf up = { 0, +1 , 0 };  //ír
    //ha meg akarja nézni, hogy a másik kiolvasott mindent
    //ezt arra lehet használni, hogy bevárja a másik folyamatot
    struct sembuf wzero = { 0, 0, 0 }; 
                  
    //TODO: szemafor tömb létrehozás

    //TODO: szemafor inicializálás 0-ra

    //TODO: fájl nyitása írásra, csonkolás

    int k; 
    for (k=0; k<N ; k++){
        cnt++;
        //TODO: minden ciklusban kiírja a cnt-t a fájlba
        //ha kiírt annyit, amekkora a szemafor maximális értéke, 
        //bevárja az olvasó folyamatot
        //semaphore max value = 32767

       //usleep(500000);//késletetés
    }    

    close(fid);
    exit(0);
}