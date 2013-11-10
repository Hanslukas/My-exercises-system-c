#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

main(int argc, char *argv[])
{
	if(argc !=2)
	{
	       printf("Usage: [sec]\n\n");
	       exit(1);
	}
	
	int childpid;
	int attesa;
	int pid_figlio;
	
	childpid = fork();
	attesa = atoi(argv[1]);
	alarm(attesa);
	getchar();


	switch(childpid)
	{
		case -1: printf("Error!!!\n");
			 exit(1);
			 break;

		case 0: printf("FIGLIO\n");
			 pid_figlio = getpid();
			 break;

		default : attesa = atoi(argv[1]);
			 alarm(attesa);
			 getchar();
			 kill(pid_figlio, SIGUSR1);
			 system("ps lax > file");
			 break;
	}
}
