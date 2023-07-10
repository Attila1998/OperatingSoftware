/* 
 * sablon az 1. feladathoz
 *
 */

#include "myinclude.h"
#include <stdio.h>

int main (int argc, char * argv[])
{
    pid_t pid;   //folyamat azonosito
    int status;  //kilepesi allapot tarolasara
    const char elvalaszto[]=" ";
    char *p;
    char exitcheck[40];
    char * parameter[10];
		

ciklus:
    //konzol
	printf("ok>");
	
	fgets(exitcheck,40,stdin);

	if((strcmp(exitcheck,"exit\n"))==0){
		goto end;	
	}
	//levagom a sorvegi ujsor karaktert amit az fgets beolvas!
	exitcheck[strlen(exitcheck)-1]=' ';

	
	
	p=strtok(exitcheck,elvalaszto);
	int i=0;
	while(p!=NULL){
	parameter[i]=p;
	p=strtok(NULL,elvalaszto);
	i=i+1;
	if(i==9)
		break;
	}
	parameter[i]=NULL;

	//debug
	//for(int j=0;j<i;j++){
	//	printf("%d\n",j);	
	//	printf("%s\n",parameter[j]);
	//}

//	goto ciklus; 

    //char parameter;
    pid = fork();  //uj folyamat
    if ( pid < 0){
        syserr("fork");
    }

    if ( pid == 0){


	//execl("/usr/bin/sort","/usr/bin/sort","-rn","szam.txt",(char*)0);

	//execlp(parameter[0],parameter[0],parameter[1],(char*)0);

	//execv("/usr/bin/sort",argumentumok);

        //ide nem ter vissza a fiu ha helyes
	execvp(parameter[0],parameter);



        syserr("execl");
    } 
     
	
        wait (&status);
	
	goto ciklus;

	end:		    


	    //apa folyamat megvarja a fiut-waintpid parancs
        
    
    exit(EXIT_SUCCESS);
}
