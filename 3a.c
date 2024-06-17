#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
// #include <sys/wait.h>

int main() {
    char *command = "ls";

    if(command==NULL){
        perror("Command Null\n");
        return 1;
    }

    pid_t pid = fork();

    if(pid==-1){
        perror("Fork Failed\n");
        return -1;
    }
    else if(pid==0)
    {
        execl("/bin/sh", "sh", "-c", command, (char *)NULL);
        _exit(EXIT_FAILURE);
    }
    else{
        int status;
        if(waitpid(pid,&status,0)==-1)
        {
            perror("Wait Failed\n");
            return 1;
        }
        else
        {
            printf("Process Exited with Exit Status: %s\n", WEXITSTATUS(status));
            return status;
        }
    }
    return 0;
}