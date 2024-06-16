#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    if(argc != 2){
        fprintf(stderr, "Usage %s <filename>", argv[1]);
        return 1;
    }

    struct stat filestat;
    if((argv[1], &filestat) == -1){
        perror("Error Reading the File!!");
        return 1;
    }

    printf("FileName : %s\n", argv[1]);
    printf("File Size: %ld bytes\n", filestat.st_size);
    printf("No. of Links: %ld bytes\n", filestat.st_nlink);
    printf("File User ID: %d\n", filestat.st_uid);
    printf("File Group ID: %d\n", filestat.st_gid);
    printf("File Modified Time: %s\n", ctime(&filestat.st_mtime));

    return 0;
}