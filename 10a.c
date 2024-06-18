#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <syslog.h>

void daemon_call()
{
    pid_t pid = fork();

    if(pid<0)
    exit(EXIT_FAILURE);

    if(pid>0)
    exit(EXIT_SUCCESS);

    if(setsid() < 0)
    exit(EXIT_FAILURE);

    umask(0);

    if(chdir("/") < 0)
    exit(EXIT_FAILURE);

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    open("/dev/null", O_RDONLY);
    open("/dev/null", O_WRONLY);
    open("/dev/null", O_RDWR);
}

int main()
{
    daemon_call();

    openlog("Daemon Details", LOG_PID, LOG_DAEMON);
    while(1)
    {
        syslog(LOG_NOTICE, "Daemon is Running");
        sleep(30);
    }
    closelog();
    return EXIT_SUCCESS;
}