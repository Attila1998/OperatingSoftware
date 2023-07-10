/* 
 * Operacios rendszer II Labor
 * az stdin masolasa az stdout-ra elso 
 * szintu read es write-al
 * karakterenként
 */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int main (int argc, char*argv[])
{
    char buff[80];

    while ( read (STDIN_FILENO, buff, 1) > 0){ // a STDIN_FILENO erteke 0
        write (STDOUT_FILENO, buff, 1);        // a STDOUT_FILENO erteke 1
    }
    exit (0);
}

