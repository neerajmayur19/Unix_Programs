#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage %s <filename> \n", argv[1]);
        return 1;
    }

    int fd = atoi(argv[1]);

    int flags = fcntl(fd, F_GETFL);
    if(flags==-1)
    {
        perror("Error Reading the Flags\n");
        return 1;
    }

    switch(flags && O_ACCMODE){
        case O_RDONLY:
            printf("Reading Only!!");
            break;
        case O_WRONLY:
            printf("Writing Only\n");
            break;
        case O_RDWR:
            printf("Reading and Writing\n");
            break;
        default:
            printf("No Permission Mode\n");
            break;
    }

    if(flags && O_APPEND)
    printf("Append\n");
    if(flags && O_NONBLOCK)
    printf("Non-Blocking\n");
    if(flags && O_SYNC)
    printf("Synchronous Operations \n");
    if(flags && O_DSYNC)
    printf("Synchronous Data Writes\n");
    if(flags && O_RSYNC)
    printf("Asynchronous Data Read\n");
    if(flags && O_CREAT)
    printf("Creating the Flag\n");

    return 0;
}