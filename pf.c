#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

main(int argc, char *argv[])
{
    int i=0, k=0, valore, *stato;
    i=atoi(argv[1]);
    int childpid;
    
    for(k=0; k<i; k++)
    {
	      switch(childpid=fork())
	      {
	          case -1: printf("Errore nella fork\n");
		                 exit(1);
		                 break;

	           case 0: printf("Figlio\n");
                     printf("Processo %d", k);
		                 exit(0);
		                 break;


      	    default: printf("Padre\n");
		                 valore=wait(stato);
		                 printf("Valore %d", valore);
		                 printf("%d", i);
		                 exit(0);
		                break;
	      }
    }
}

