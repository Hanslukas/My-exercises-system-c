#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>

main(int argc, char *argv[])
{
	if(argc !=3)
	{
		printf("Error\n");
		printf("Usage: [sec] [PID]\n\n");
		exit(1);
	}

	int intervallo;
	int pid;
	int err;
	pid = atoi(argv[2]);
	intervallo = atoi(argv[1]);

	printf("PID: %d\n", pid);
	printf("Intervallo : %d\n", intervallo);



	err = kill(pid, SIGUSR1);
	alarm(intervallo);

	if(err==-1)
		printf("Error!!! Processo inesistente\n");
	else
		printf("Segnale inviato\n");

}
