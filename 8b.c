#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    pid_t pid = fork();
    int status;
    if(pid<0)
    {
        perror("Forking Error\n");
        exit(EXIT_FAILURE);
    }
    else if(pid==0)
    {
        pid_t child_pid = getpid();
        printf("Child PID: %d\n", child_pid);

        if(access("source.txt", F_OK)==0)
        printf("Child Process has access to the File and the File exists\n");
        else
        printf("Either the File does not exist or the Child Process does not have access\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        pid_t parent_pid = getpid();
        printf("Parent PID: %d\n", parent_pid);

        waitpid(pid,&status,0);
        printf("Parent: Child with %d PID has exited\n", pid);
    }
    return 0;
}