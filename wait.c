#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

main()
{
    int childpid;
    int *stato, valore;

    childpid=fork(); 

   switch(childpid)
   {
    case 0:
	    printf("Figlio\n");
	    getchar();
	    break;
	    
    case -1: printf("Errore\n");
	     break;
	     
    default:
	     printf("Padre\n");
	     valore= wait(stato);
	     printf("Valore %d", &valore);
		   exit(0);
	     break;
   }
}
