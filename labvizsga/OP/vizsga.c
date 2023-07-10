#include "myinclude.h"


int main(int argc, char *argv[]){

//valtozo inicializalas
pid_t fiu1,fiu2;
int semid,shmid;
key_t key;
char * shmp; //ide mentjuk osztott memoria szegmens kezdo cime
char * uzenet;
char buff[80];
FILE* fd;
int * a;
int * b;
int * c;
//kulcs : /usr/bin 30
key=ftok("user/bin",30);
//fajlnev szoveg.txt

fd=open("szoveg.txt",O_CREAT|O_RDONLY,0666);
if(fd<0){perror("Open");return errno;}

//system v eroforrassok inicializalasa
struct sembuf down0 = {0, -1, 0};
struct sembuf up0 = {0, 1, 0};
struct sembuf down1 = {1, -1, 0};
struct sembuf up1 = {1, 1, 0};

//szemafor tomb lefoglalasa 4 szemafor
if((semid=semget(key,4,IPC_CREAT|0660))<0)
syserr("szemafor");
//szemafor inicializalas szem0=1 szem1=0
if(semctl(semid, 0, SETVAL, 1) == -1 || semctl(semid, 1, SETVAL, 0) == -1)
syserr("szemafor beallitas");

//osztott memoria lefoglalasa 3 db int 1* 10db char
if((shmid=shmget(key,3*sizeof(int)+(10*sizeof(char)),0660 |
IPC_CREAT))<0)
syserr("memoria");
//osztott memoria felcsatolasa
shmp = (char *) shmat(shmid,NULL,0);
if(shmp==(void *) -1)
syserr("memory at");

a=(int*)shmp;
b=shmp+sizeof(int);
c=shmp+2*sizeof(int)
uzenet=shmp+2*sizeof(int)+(10*sizeof(char));
//folyamatok letrehozasa
if((fiu1=fork())<0) syserr("fork1");

if (fiu1==0){
//kritikus szekcio
if(semop(semid,&down0,1)<0) syserr("semdown")
printf("fiu1: apa pid:%d sajat pid:%d\n",getppid(),getpid());

while(buff != EOF)
{
	read(fd,buff,1)
	if(strcmp(buff,"a")){a++;}
	if(strcmp(buff,"b")){b++;}
	if(strcmp(buff,"c")){c++;}
	else(strcpy(buff,uzenet);)
	
}
if(semop(semid,&up1,1)<0) syserr("semdown");
if (shmdt((void*) shmp)<0) syserr("dt");
exit(0);
}

if((fiu2=fork())<0) syserr("fork3");
if (fiu2==0){
// kritikus szekcio
if(semop(semid,&down1,1)<0) syserr("semdown")
printf("fiu2: apa pid:%d sajatpid:%d\n",getppid(),getpid());
printf("uzenet: %s \n",uzenet);
if(semop(semid,&up0,1)<0) syserr("semdown");
if (shmdt((void*) shmp)<0) syserr("dt");
}


//folyamatok befejeztenek megvarasa

wait(NULL);
wait(NULL);

//system v eroforrasok torlese

printf("a erteke: %i\n ",a)
printf("b erteke: %i\n ",b)
printf("c erteke: %i\n ",c)
fclose(fp);
if (shmdt((void*) shmp)<0) syserr("dt");
if(semctl(semid,0,IPC_RMID)<0) syserr("sem del");
if(shmctl(shmid,IPC_RMID,0)<0) syserr("ctl2"); 

exit(0);
}
