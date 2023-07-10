#include "myinclude.h"


int main(int argc, char* argv[])
{
    pid_t fiu;
    pid_t fiu2;
    int fd [2];
    char buff[512];
    int f1,f2,i;
    int status;


    pipe(fd);



    if ( (fiu = fork()) < 0 ){
        perror("fork 1");
    }

    if ( fiu == 0 ){
        /*szabaly: a folyamat lezarja a csovezetek azon felet amelyet nem hasznal*/
        close (fd[1]); /* olvasni fog, az iras felet lezarja */
        /* atirja a sztringet */
        //if (read( fd[0], buff, strlen(buff)+1)<0){
       //     perror("read f");         }
        if ((i=read( fd[0], &buff[0], 512))<0)  /*beolvasaskor rendelkezesre bocsajtom a buff teljes meretet 512 i az az ertek ahany bytot olvastam*/
            perror("read fd0");

        f2 = open(argv[2], O_CREAT| O_TRUNC | O_RDWR, 0666);

        if (write(f2, &buff[0], i)<0){
            perror("write f2:");
        }
        close(f2);  /*vegen zarok le mindent*/
        close (fd[0]);
        exit(0);
    }

    close (fd[0]) ; //iras
        /* ez a folyamat olvas: amig a fiu nem ir a csobe,
           addig a folyamat a read-nel blokkolva van
           a read akkor ter vissza, ha MAX karaktert olvasott
           vagy a masik fel lezarja a csovezeteket
           */

        if((f1 = open(argv[1], O_RDONLY))<0)
             perror("open f1");

        if ((i=read(f1, &buff[0], 512))<0)
            perror("read f1");

        if (write ( fd[1], &buff[0], i)<0)
            perror("write fd1:");


         wait (&status);  /* elso fiura var */



        if ( (fiu2 = fork()) < 0 ){
        perror("fork 2");
        }

    if ( fiu2 == 0 ){
        execlp("cmp", "cmp", argv[1],argv[2] ,NULL);
        exit(1);
    }

    wait (&status);  /* masodik fiura var */

    if(status == 0){
        printf("oke");
    }

    close(f1);
    exit(0);
}
