#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>


int main(int argc, char **argv)
{
    int figlio,i,j;
    char **parametri=(char**)malloc((argc-1)*sizeof(char*));
    
    if(argc < 2)
    {
        printf("usage: %s <program> <parameters>\n");
        exit(1);
    }

    for(i=1,j=0; i <= argc; i++,j++)
        parametri[j]=argv[i];
    
    parametri[argc]=NULL;

    if((figlio=fork()) == -1)
    {
        printf("Errore nella creazione del figlio\n");
        exit(1);
    }
    else if(figlio == 0)
    {
        printf("Sono dentro al figlio\n\n");    
        if(execvp(argv[1],parametri) == -1)
        {
            printf("Errore\n");
            exit(1);
        }
        else
            exit(0);
    }
    else
    {
        wait((int*)0);
        exit(0);
    }
}
