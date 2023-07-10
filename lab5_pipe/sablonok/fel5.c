/* 
   5. feladat sablon
   2 fiú szinkronizálása pipe-al

   TODO: a szinkronizálás meg van írva, írjuk meg a feladat
   alábbi követelményét:
  - apa létrehoz egy fájlt amíg a fiúk várnak, benne "Helló" szöveg
  - fiúk kiírják a terminálra a fájlt miután újraindulnak

*/

#include "myinclude.h"

int main(int argc, char *argv[])
{
  int pfd[2]; //pipe azonosítók
  pid_t p1, p2;
  char b;

  setbuf(stdout, NULL); //pufferelés tiltása

  //cső
  if (pipe(pfd) < 0)
    syserr("pipe");

  //első fiú
  if ((p1 = fork()) < 0)
    syserr("p1:");

  //első fiú folyamat
  if (p1 == 0)
  {
    //olvasni fog a csőből
    close(pfd[1]);
    printf("fiú 1 vár\n");

    //próbál egy byte-ot olvasni, blokkolódik
    if (read(pfd[0], &b, 1) < 0) syserr("read2");

    printf("fiú 1 fut\n");
    exit(EXIT_SUCCESS);
  }

  //apa folytatja, 2. fiú létrehozása
  if ((p2 = fork()) < 0)
    syserr("p2:");

  //fiú 2
  if (p2 == 0)
  {
    //olvasni fog
    close(pfd[1]);
    printf("fiú 2 vár\n");

    //olvasni próbál, blokkolódik
    if (read(pfd[0], &b, 1) < 0) syserr("read1");
      
    printf("fiú 2 fut\n");
    exit(0);
  }

  //apa dolgozik
  //írni fog a csőbe
  close(pfd[0]);

  //apa
  printf("apa dolgozik\n");
  sleep(5);
  printf("apa befejezte\n");

  //vár egy keveset, fájl záródik
  usleep(100000); //100ms

  //ha lezárja a csövet, a két read visszatér fájl vége 0-val
  //és a két fiú folyamat újra indul
  //ha írtunk volna 2 byte-ot és utána zárjuk a csővet ugynaz történik
  close(pfd[1]);

  //megvárja a fiait
  wait(NULL);
  wait(NULL);
  exit(EXIT_SUCCESS);
}
