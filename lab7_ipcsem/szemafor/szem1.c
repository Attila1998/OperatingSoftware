#include "myinclude.h"


int main(){

int semid; //szemafor azonosito

key_t key;


//ket muvelet a 0 szemaforon down szemafor0-1  up szemafor0+1
struct sembuf down = {0, -1, 0};
struct sembuf up = {0, 1, 0};

//ket muvelet az 1 szemaforon down1 szemafor1-1 up1 szemafor1+1
struct sembuf down1 = {1, -1, 0};
struct sembuf up1 = {1, 1, 0};

//kulcs deklaralasa ahany folyamat fogja hasznalani ezt a szemafort ez a kulcs ugyanaz kell legyen!
key=ftok("/usr/bin",46);

//letrehozom a szemafort ha a kulcs nem letezik ha letezik csatlakozom ra ha van hozza jogom
if((semid=semget(key,2,IPC_CREAT|0660))<0)
	syserr("szemafor letrehozas");

//beallitom a 0 szemafor erteket 0 az 1-es szemafor erteket 1 
if(semctl(semid, 0, SETVAL, 0) == -1 || semctl(semid, 1, SETVAL, 1) == -1)
	syserr("szemafor beallitas");







}
