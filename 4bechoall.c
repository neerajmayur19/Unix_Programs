#include <stdio.h>

int main(int argc, char* argv[], char* envp[])
{
    printf("Argument Values\n");
    for(int i=0;i<argc;i++)
    {
        printf("argv[%d]: %s", i,argv[i]);
    }
    for(int i=0;envp[i] != NULL;i++)
    {
        printf("envp[%d]: %s", i, envp[i]);
    }
    return 0;
}