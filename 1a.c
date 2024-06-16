#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if(argc != 2){
        fprintf(stderr, "Usage %s <filename>", argv[1]);
        return 1;
    }
    int fd = open(argv[1], O_RDONLY);
    if(fd==-1)
    {
        perror("Error in Opening the File");
        return 1;
    }
    off_t file_size = lseek(fd, 0, SEEK_END);
    if(file_size==-1)
    {
        perror("Error in Seeking the File");
        close(fd);
        return 1;
    }
    for(off_t i=1;i<=file_size;i++)
    {
        if(lseek(fd,-i,SEEK_END)==-1)
        {
            perror("Error in Seeking to end of the File");
            close(fd);
            return 1;
        }
        char ch;
        if(read(fd,&ch,1)!=1)
        {
            perror("Error in Reading the End of the File\n");
            close(fd);
            return 1;
        }
        putchar(ch);
    }
    close(fd);
    return 0;
}