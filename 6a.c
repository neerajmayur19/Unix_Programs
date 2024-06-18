#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>

int main()
{
    struct dirent* dir;
    DIR* dp;
    int fd, n;
    dp = opendir(".");
    if(dp)
    {
        while(dir=readdir(dp) != NULL)
        {
            int fd = open(dir->d_name, O_RDWR, 0777);
            int n = lseek(fd, 0, SEEK_END);
            if(!n)
            {
                unlink(dir->d_name);
            }
        }
    }
}