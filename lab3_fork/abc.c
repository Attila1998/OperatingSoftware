/* 
 *  Labor 3, Feladat 1 sablon
 */

#include "myinclude.h"

//n darab c karaktert ír a name nevű fájlba
int makefile(char * name, char c, int n)
{
    int fd;
    int status;
    //TODO: nyissuk meg írásra, új fájl, csonkolással
    fd=open(name,O_CREAT|O_WRONLY|O_TRUNC,0666); //rwx   r=4  w=2 x=1
    if(fd<0){
	//syserr("open");
	perror("open");
	return errno;    
    }
    //TODO: for ciklus n-szer, minden ciklus egyszer 
    //kiírja a c karaktert a fájlba
    for(int i=0;i<n;i++){
    	status=write(fd,&c,1);
	if(status<1){
		//syserr("write");
		perror("write");
		return errno;
	}
    }
    //fájl zárás
    close(fd);
    return 0;
}


int main(int argc, char *argv[])
{
    pid_t pid1, pid2; //folyamat azonosítók
    int status1, status2; //kilépési állapotok átvételéhez

    //első fiú indítása
    if ( (pid1=fork()) < 0) {
        syserr("f1");
    }
    if (pid1==0) { //itt indul fiu1 folyamat
        //TODO: első fiú kódja
        status1=makefile("a.txt",'a',100);
	//sleep(30);
	if(status1==0){
        	exit(EXIT_SUCCESS);//a fiú itt mindenképp kilép, így
        }
	else{
		printf("fiu1 hiba kod: %i",status1);
		exit(EXIT_FAILURE);
	}                   //nem futhat rá a következő kódokra  
			//itt vegzodik fiu1 folyamat
    }
	// az apa innen folytatja a vegrehajtast pid1!=0
    //TODO: második fi
    //második fiú indítása
    if ( (pid2=fork()) < 0) {
        syserr("f2");
    }

    //TODO: második fiú kódja

    if (pid2==0) { //indul a fiu2 folyamat
	//csak a fiu2 lep be
	status2=makefile("b.txt",'b',100);	
	//sleep(30);
        if(status2==0){
                exit(EXIT_SUCCESS);//a fiú itt mindenképp kilép, így
        }
	else{
                printf("fiu2 hiba kod: %i",status2);
                exit(EXIT_FAILURE);                   
        }   
    }

    //TODO: apa kódja, itt ír a fájlba
    status1=makefile("c.txt",'c',100);

        if(status1!=0)
                printf("fiu1 hiba kod: %i",status1);

   //sleep(50);
    //apa megvárja mindkét fiát 
    wait(&status1);
    wait(&status2);

    exit(EXIT_SUCCESS);
}      
