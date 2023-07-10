#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/unistd.h>

int main(){
int  x=2;
pid_t pid,apa,fiu,fiu2;

pid = getpid();
apa = getppid();

printf("en idm: %d\n",pid);

printf("apa idm: %d\n",apa);

if((fiu=fork())<0)
	exit(1);

//apa folyamat fiu=8678  a fiu folyamatban fiu=0

if(fiu==0)  //ide csak a fiu lep be 
{
//csak a fiu hajtja vegre
	x=x+34;
	printf("fiu valtozo %d\n",x);
	exit(0);
}
if((fiu2=fork())<0)
	exit(1);
if(fiu2==0)
{
//csak fiu2 hajtja vegre
	x=x+22;
	printf("fiu2 valtozo %d\n",x);
	exit(0);
}


printf("apa valtozo: %d",x);
wait(NULL);
wait(NULL);


exit(0);
}
