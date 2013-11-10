#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

char *messaggio;

void stampa()
{
     printf("%s\n",messaggio);
     exit(0);
}

main(int argc, char *argv[])
{
	 int a;
   if(argc != 3)
   {
     printf("Error! \n");
     printf("\nUsage: [name progr] [sec] [string]\n");
     exit(1);
   }
   messaggio = (char *)malloc(strlen(argv[2])*sizeof(char));
   strcpy(messaggio,argv[2]); 

   a = atoi(argv[1]);
   signal(14,stampa); 
   alarm(a);
   getchar();
}
