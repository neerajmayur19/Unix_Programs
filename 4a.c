#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage %s <filename>\n", argv[1]);
        return 1;
    }

    const char* original_file = argv[1];
    char hard_link[256];
    char soft_link[256];
    struct stat filestat;

    int fd = open(original_file, O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if(fd<0)
    {
        perror("Error Reading the File\n");
        exit(EXIT_FAILURE);
    }
    write(fd, "Hello, World!", 14);
    close(fd);

    if(link(original_file,hard_link)<0)
    {
        perror("Error Hard Linking\n");
        exit(EXIT_FAILURE);
    }

    if(symlink(original_file,soft_link)<0)
    {
        perror("Error Soft Linking\n");
        exit(EXIT_FAILURE);
    }

    printf("Original File Info:\n");
    if(stat(original_file, &filestat)==0)
    {
        printf("Inode: %ld\n", (long)filestat.st_ino);
        printf("File Size: %ld\n", (long)filestat.st_size);
        printf("Number of Hard Drive Links: %ld\n", (long)filestat.st_nlink);
        printf("Access Time: %s\n", ctime(&filestat.st_atime));
        printf("Modification Time: %s\n", ctime(&filestat.st_mtime));
        printf("Status Time Changes: %s\n", ctime(&filestat.st_ctime));
    }
    else
    {
        perror("Stat Error\n");
    }

    printf("Hard Link File Info:\n");
    if(stat(hard_link, &filestat)==0)
    {
        printf("Inode: %ld\n", (long)filestat.st_ino);
        printf("File Size: %ld\n", (long)filestat.st_size);
        printf("Number of Hard Drive Links: %ld\n", (long)filestat.st_nlink);
        printf("Access Time: %s\n", ctime(&filestat.st_atime));
        printf("Modification Time: %s\n", ctime(&filestat.st_mtime));
        printf("Status Time Changes: %s\n", ctime(&filestat.st_ctime));
    }
    else
    {
        perror("Stat Error\n");
    }

    printf("Soft Link File Info:\n");
    if(stat(soft_link, &filestat)==0)
    {
        printf("Inode: %ld\n", (long)filestat.st_ino);
        printf("File Size: %ld\n", (long)filestat.st_size);
        printf("Number of Hard Drive Links: %ld\n", (long)filestat.st_nlink);
        printf("Access Time: %s\n", ctime(&filestat.st_atime));
        printf("Modification Time: %s\n", ctime(&filestat.st_mtime));
        printf("Status Time Changes: %s\n", ctime(&filestat.st_ctime));
    }
    else
    {
        perror("Stat Error\n");
    }

    if(unlink(original_file)<0)
    perror("Error Unlinking\n");

    if(unlink(hard_link)<0)
    perror("Error Unlinking\n");

    if(unlink(soft_link)<0)
    perror("Error Unlinking\n");

    return 0;
}