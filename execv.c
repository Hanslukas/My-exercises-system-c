#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

main(int argc, char *argv[])
{
    int childpid;
    int *stato, valore;

	   switch(childpid=fork())
	   {
	      case 0: execv(&argv[argc-1], argv[1]);  
		            exit(0);
		            break;

	      case -1: printf("Errore\n");
		             break;

	      default: valore=wait(stato);
		             exit(0);
		             break;
		   
	  }
}
