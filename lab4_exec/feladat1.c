/* 
 * sablon az 1. feladathoz
 *
 */

#include "../myinclude.h"

int main (int argc, char * argv[])
{
    pid_t pid;   //folyamat azonosito
    int status;  //kilepesi allapot tarolasara


    pid = fork();  //uj folyamat
    if ( pid < 0){
        syserr("fork");
    }



    if ( pid == 0){

        //TODO: ide beirni az exec hivasokat
        //egyszerre egyet, kiprobalni es utana
        //magyarazatba tenni
	
	//  parameterek es argumentumok atadasa listaban
	//elso a vegrehajtando program neve  //masodik a belepesi pont altalaba ugyanaz mint az elso //tobbi argumentum
	
	//execl("/usr/bin/sort","/usr/bin/sort","-rn","szam.txt" ,(char*) 0);

	//execlp("sort","sort","-rn","szam.txt" ,(char*) 0);
	
	//char * argumentumok[] = {"/usr/bin/sort", "-rn", "szam.txt", NULL};

	char * argumentumok[] = {"sort", "-rn", "szam.txt", NULL};

	//execv("/usr/bin/sort",argumentumok);

	execvp("sort",argumentumok);


        //ide nem ter vissza a fiu ha helyes
        syserr("execl");
    } else
    {  
        //apa folyamat megvarja a fiut 
        wait (&status);
        
        //TODO: az apa irja ki, hogy milyen exit koddal 
        //vagy jelzessel lepett ki a fiu
    }
    exit(EXIT_SUCCESS);
}
