//Simulate Copy Command
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.H>
#include <string.h>
#include <errno.h>

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        fprintf(stderr, "Usage %s <filename>\n",argv[0]);
        return 1;
    }

    char* source_file = argv[1];
    char* destination_file = argv[2];
    int src_fd, dest_fd;
    ssize_t bytes_read, bytes_written;
    char buf[100];

    src_fd = open(source_file,O_RDONLY);
    if(src_fd<0)
    {
        perror("Error Reading the File\n");
        exit(EXIT_FAILURE);
    }

    dest_fd = open(destination_file, O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if(dest_fd < 0)
    {
        perror("Error Writing the File\n");
        exit(EXIT_FAILURE);
    }

    while((bytes_read = read(src_fd, buf, 100))>0)
    {
        bytes_written = write(dest_fd,buf,bytes_read);
        if(bytes_read != bytes_written)
        {
            perror("Error Writing the File\n");
            close(src_fd);
            close(dest_fd);
            exit(EXIT_FAILURE);
        }
        else
        {
            printf("Succesfully Copied\n");
        }
    }

    if(bytes_read < 0)
    {
        perror("Error in Main Operation\n");
        exit(EXIT_FAILURE);
    }

    close(src_fd);
    close(dest_fd);
    return 0;
}