#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    int file = 0, n;
    char buffer[100];

    if((file=open("source.txt",O_RDONLY)<0))
    {
        perror("Error Opening the File\n");
        exit(EXIT_FAILURE);
    }

    if((read(file,buffer,20)) != 20)
    perror("Error Reading 20 bytes from the File\n");
    else
    write(STDOUT_FILENO,buffer,20);

    if(lseek(file,20,SEEK_SET)<0)
    perror("Error Seeking 20 bytes from the Beginning of the File\n");
    else
    {
        if(read(file,buffer,20) != 20)
        perror("Error Reading 20 bytes from the Beginning of the File\n");
        else
        write(STDOUT_FILENO,buffer,20);
    }

    if(lseek(file,20,SEEK_CUR)<0)
    perror("Error Seeking 20 bytes from the Current Part of the File\n");
    else
    {
        if(read(file,buffer,20) != 20)
        perror("Error Reading 20 bytes from the Current Part of the File\n");
        else
        write(STDOUT_FILENO,buffer,20);
    }

    if((n=lseek(file,0,SEEK_END))<0)
    perror("Error Reaching the end of the File\n");
    else
    printf("The Size of the File is %d bytes\n", n);

    return 0;
}