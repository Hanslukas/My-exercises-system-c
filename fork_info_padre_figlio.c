#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <grp.h>
#include <pwd.h>

main()
{
    int childpid;
    int x, y, grp, grpf;
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
	          system("ps lax > file1");
	          getenv("HOME");
	          getenv("SHELL");
	          x=getuid();
	          grp=getgid();
	          printf("%d", x);
	          printf("%d", grp);
	          exit(0);
	          break;

			      case -1: printf("Errore\n");
			      break;
            
            default: printf("padre: pid figlio=%d, pid padre=%d\n", childpid, getpid());
                     system("ps lax >> file 1");
                     getenv("HOME");
                     getenv("SHELL");
                     y=getuid();
                     grpf=getgid();
                     printf("%d", y);
                     printf("%d", grpf);
                     exit(0);
                     break;
		   
	      }
    }
}
