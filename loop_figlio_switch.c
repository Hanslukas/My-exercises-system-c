#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

main()
{
    int childpid;

    childpid=fork(); 

    switch(childpid)
    {
        case 0:
	          printf("Figlio\n");
	          while(1)
	          {
		            printf("PID: %d, PPID:%d", getpid(), getppid());
		            sleep(1);
		
	          }
	          break;
        case -1: printf("Errore\n");
	          break;
        default:
	          printf("Padre\n");
	          if(getchar())
		            exit(0);
	          break;
    }
}
