#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>
#include <sys/stat.h>

int main(){
    struct dirent* dir;
    struct stat filestat;
    DIR* dp;
    dp = opendir(".");
    if(dp){
        while(dir=readdir(dp))
        {
            if(stat(dir->d_name,&filestat)==-1)
            {
                perror("File Stat Error\n");
                continue;
            }
            printf("%d\t%o\t%d\t%d\t%s\t%s\n", filestat.st_nlink, filestat.st_mode, filestat.st_uid, filestat.st_gid, ctime(&filestat.st_atime), dir->d_name);
        }
    }
    return 0;
}