#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

main(int argc, char *argv[])
{
	int figlio1, figlio2, figlio3;

	figlio1=fork();

	switch(figlio1)
	{
		case -1: printf("Error\n");
			       exit(1);
			       break;

		case 0:	 printf("PID Figlio 1 : %d\n", getpid());
			       figlio2=fork();
			       if(figlio2==-1)
			       {
				          printf("Error\n");
				          exit(1);
			       }
			       else
			 
				     if(figlio2==0)
					       printf("PID Figlio 2 : %d\n", getpid());
			 			     figlio3=fork();
			       if(figlio3==-1)
			       {
				         printf("Error\n");
				         exit(1);
			       }
			       else
			           if(figlio3==0)
					            printf("PID Figlio 3 : %d\n", getpid());
			      break;
		        
		default : printf("PID Padre : %d\n", getpid());
			        break;
	}
	getchar();
}
