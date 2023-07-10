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
char random[4];
unsigned int num;

rnd=open("/dev/urandom",O_RDONLY,0666);
	if(rnd<0){
		perror("nyitas hiba: ");
		exit(1);
	}

	err=read(rnd,&random[0],4);
	if(err<0){
		perror("nyitas hiba: ");
		exit(1);
	}
	memcpy ( &num, &random[0], 4 );
	
	printf("Random szam: %u\n",num);


close(rnd);



exit(0);
}
