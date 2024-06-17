#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>

void signal_handler(int num)
{
    printf("SIGINT called (Signal Number:%d)\n",num);
    struct sigaction sa;
    sa.sa_handler = SIG_DFL;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);
    
    if(sigaction(SIGINT,&sa,NULL)==-1)
    {
        perror("Sigaction Error\n");
        exit(EXIT_FAILURE);
    }
}

int main()
{
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    if(sigaction(SIGINT,&sa,NULL)==-1)
    {
        perror("Sigaction Error\n");
        exit(EXIT_FAILURE);
    }
    printf("Press Ctrl+c for the first time to Pause. Then the next time, the action will be restored\n");
    while(1)
    {
        pause();
    }
    return 0;

}