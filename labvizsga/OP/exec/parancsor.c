#include "myinclude.h"

#define MAX 256

int main (int argc, char * argv[])
{      
    pid_t pid;
    int status;
    char parancs[MAX];

    enum { MAX_ARGS = 64 };
    char *args[MAX_ARGS];
    char **next = args;
	char *temp;

	start_ciklus:

	printf("ok>");
	if ( fgets (parancs, MAX, stdin) == NULL){    /*olvasas stdin-rol*/
        printf("olvasas hiba\n");
        exit(1);
    }
	
	parancs[strlen(parancs)-1]='\0';

	if(strcmp(parancs,"exit")==0)
		goto end_ciklus;

	

    pid = fork();
    if ( pid < 0){
        syserr("fork");
    }

    if ( pid == 0){

		temp = strtok(parancs, " ");
		while (temp != NULL)
		{
		    *next++ = temp;
			//printf("%s\n", temp);
		    temp = strtok(NULL, " ");
		}
		*next = NULL;
		execvp(args[0], args);

        /* ide mar nem ter vissza */
        syserr ("execv hiba\n");
    } 

	*args = NULL ;
    /*apa folyamat megvarja a fiut */
    wait (&status);
	goto start_ciklus;
	end_ciklus:
	exit(0);
}

