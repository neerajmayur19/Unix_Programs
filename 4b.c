#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


extern char **environ;

int main()
{
    pid_t pid = fork();

    if(pid<0)
    {
        perror("Forking the File\n");
        return -1;
    }
    else if(pid==0)
    {
        char *args[] = {"./4binterpreter.sh","child_arg1""child_arg2",NULL};
        char *envp[] = {"CHILD_ENV1=value1","CHILD_ENV2=value2",NULL};
        execve("./4binterpreter.sh",args,envp);
        perror("Failure\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        int status;
        waitpid(pid,&status,0);
        char *args[] = {"./4binterpreter.sh","parent_arg1""parent_arg2",NULL};
        execve("./4binterpreter.sh",args,environ);
        perror("Failure\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}