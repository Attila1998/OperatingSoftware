#include "myinclude.h"

#include "file.h"

int main( int argc, char * argv[])
{
    int semid;
    char fname[] = "a.dat";
    int cnt ; //ide olvas

    //csak akkor olvas ha ez a műveletet elvégezhető
    struct sembuf down  = { 0, -1 , 0 };

    //TODO: szemafor tömb lekérése, ha nincs hiba

    //TODO: ellenőrzi, megjelent-a a fájl
    //ha nem, akkor vár 0,5 szekundumot és megismétli
    //ha megjelent, tovább fut

    
    //fájl nyitás olvasásra
    int fid;

    int k;
    for (k=0; k<N ; k++){
        //TODO: olvas egy egészet, ha van mit: ha el lehet végezni a szemafor műveletet
    }    

    //TODO: törli a szemafor tömböt

    //TODO: törli a fájlt
    exit(0);
}

