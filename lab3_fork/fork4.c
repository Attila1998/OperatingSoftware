/*
 * Hibas kod!!!
 * hany folyamat van a peldaban ? 
 * hany c valtozo van? 
 * mennyi a c valtozok erteke amikor minden folyamat kilep?
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char ** argv)
{
        int c;
		int child = fork();
		c = 5;

		if(child == 0)
		{
				c += 5;
		}
		else
		{
				child = fork();
				c += 10;
				if(child)
					c += 5;
		}
    exit(0);
} 
