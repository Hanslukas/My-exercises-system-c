#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

main(int argc, char *argv[])
{
    int childpid;

	  switch(childpid=fork())
	  {
	       case 0: execl("/bin/ls","ls","-l",(char *)0);
		             exit(0);
		             break;

	       case -1: printf("Errore\n");
		              break;

	       default: valore=wait(stato);
		              exit(0);
		              break;
		   
	  }
}
