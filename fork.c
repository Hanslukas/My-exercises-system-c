#include <stdio.h>
#include <stdlib.h>

main()
{
    int childpid;
    int m;
    if ((childpid = fork()) == -1)
    {
	      printf("Errore nella fork\n");
	      exit(1);
    }
    else
    {
	      switch(childpid)
	      {
	          case 0: printf("figlio: pid figlio=%d, pid padre=%d\n", getpid(), getppid());
	                  exit(0);
	                  break;

			      case -1: printf("Errore\n");
  		               break;

			      default: printf("padre: pid figlio=%d, pid padre=%d\n", childpid, getpid());
				             exit(0);	
				             break;
		   
	      }
    }
}
