#include <stdio.h>
#include <sys/stat.h> 
#include <sys/types.h> 
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){

int rnd;
int err;
char szoveg[13]="Ez egy szoveg\n";


rnd=open("/dev/stdout",O_WRONLY,0666);
	if(rnd<0){
		perror("nyitas hiba: ");
		exit(1);
	}

	err=write(rnd,&szoveg[0],13);
	if(err<0){
		perror("nyitas hiba: ");
		exit(1);
	}


//kiiras a mar megnyitott stdoutra

	err=write(1,&szoveg[0],13);
	if(err<0){
		perror("nyitas hiba: ");
		exit(1);
	}

close(rnd);



exit(0);
}
