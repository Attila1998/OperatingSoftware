/*
 * 1. feladat sablonja 
 * apa átmásol bármilyen fájlt a fiának egy csövön,
 * akár szöveges, akár bináris a fájl
 *
 *  binárisan másol, nem nézik mi a tartalom
 */

#include "myinclude.h"

#define MAXBUFF 80

//a fiú feladata
//be: pfd0: cső olvasható vége, nev: kimeneti fájl
void fiu_feladat (int pfd0, char * nev)
{
    int fd,n; //fájl beolvasni 
    char buff[MAXBUFF]; 
    int count = 0;

    //TODO: megnyitjuk írásra a fájlt, név a nev-ben
    //      O_WRONLY | O_TRUNC | O_CREAT
    
	fd=open(nev,O_WRONLY | O_TRUNC | O_CREAT)
		if(fd<0)
		syserr("iras");
    //TODO: -olvasunk MAXBUFF byte-ot a csőből: pfd0
    //      -írunk n byte-ot a fájlba
    //      -számoljuk hány byte-ot olvastunk összesen a count-ban
    //      -minden hibát ellenőrzünk

    //TODO: lezárjuk a csövet meg a fájlt is

    printf("masolás összesen: %d byte\n",count);
}

//az apa feladata
//be: pfd1: cső írható vége, nev: bemeneti fájl
void apa_feladat (int pfd1, char * nev)
{
    int fd,n; char buff[MAXBUFF]; 

   //TODO: megnyitjuk olvasásra a fájlt, név a nev-ben
   //      O_RDONLY
	fd=open(nev,O_RDONLY)
	if(fd<0)
		syserr("olvasas");
   //TODO: olvasunk MAXBUFF byte-ot a fájlból
   //      írunk n byte-ot a csőbe
   //      minden hibát ellenőrzünk
	while(n=read(fd,&buff,MAXBUFF)>0)
		
   //TODO: lezárjuk a csövet és a fájlt
}


int main(int argc, char * argv[])
{
    pid_t pid;   //fiú pid
    int pfd[2];  // cső 
    int status;

    //két különböző paraméter
    if (argc!=3){
        printf("Használat %s fájl-be fájl-ki\n", argv[0]); 
        exit(1);
    }
    if (!strcmp(argv[1],argv[2])){
        printf("a két fájlnév név ugyanaz!\n"); exit(1);
    }

    //TODO: megnyitjuk a csövet
    //pfd változóban lesz a két azonosító
    //hiba ellenőrzés!

    //TODO: elondítjuk a fiút, pid-ben a folyamat azonosító

    //fiú:
    if (pid==0){
        //TODO: lezárjuk a cső írható végét

        //TODO: elindítjuk a fiú feladatot
        //fiu_feladat ( ... ,argv[2]); //feladat
        exit(EXIT_SUCCESS);
    }
    //apa feladatai:

    //TODO: lezárjuk a cső olvasható véget

    //TODO: elindítjuk az apa feladatot
    //apa_feladat ( ... ,argv[1]); //feladat 
    
    wait(&status);

    /* a feladat 2. részéhez ezt a megjegyzést kivenni

    //ha hiba nélkül lépett ki a fiú
    if (WIFEXITED(status) && WEXITSTATUS(status)==0){
        printf("exit fiú ok\n");
        
        //második fiút indítunk
        if ( (pid=fork()) < 0) {
            syserr("fork");
        }

        //a második fiúban elindítjuk a cmp-t
        if (pid==0){
            //TODO: execlp-vel indítjuk a cmp-t, argv[1] és argv[2] összehasonlításra

            syserr("execlp");
        }     

        wait(&status);

        if (WIFEXITED(status) && WEXITSTATUS(status)==0){
            printf("a két fájl egyforma\n"); 
        }else
        {
            printf("összehasonlítás nem sikerült\n"); 
        }
    }
    */ //eddig a feladat 2. részéhez szükséges kód

    exit(EXIT_SUCCESS);

}
