#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/unistd.h>
int main (int argc, char * argv[]){
pid_t fiu;
int status;
if((fiu = fork())==-1){
perror("fork:");
exit(1);
}
printf("teszt uzenet ketszer\n");
if(fiu == 0){
	printf("fiu sajat_pid: %d, apa_pid: %d\n",getpid(),getppid());
	sleep(20);
	exit(0);
}
printf("apa sajat_pid: %d, apa_pid: %d\n",getpid(),getppid());
sleep(30);
wait(&status);
exit(0);
}
