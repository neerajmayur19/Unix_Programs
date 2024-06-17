#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <utime.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        fprintf(stderr, "Usage %s <filename>\n",argv[0]);
        return 1;
    }

    const char* source_file = argv[1];
    const char* destination_file = argv[2];

    struct stat file_stat;
    struct utimbuf new_times;

    if(stat(source_file,&file_stat)<0)
    {
        perror("Stat Error\n");
        exit(EXIT_FAILURE);
    }

    new_times.actime = file_stat.st_atime;
    new_times.modtime = file_stat.st_mtime;

    if(utime(destination_file,&new_times)<0)
    {
        perror("Utime Error\n");
        exit(EXIT_FAILURE);
    }
    printf("Successfully Copied\n");
    return 0;
}