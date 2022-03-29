#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[])
{
    int fd1, fd2;
    int length;
    char buf[BUFFER_SIZE];

    if(argc != 4)
    {
        fprintf(stderr, "Usage : %s <offset> <data> <file>\n", argv[0]);
        exit(1);
    }

    if((fd1 = open(argv[3], O_WRONLY)) < 0)
    {
        fprintf(stderr, "open error for %s\n", argv[3]);
        exit(1);
    }

    if(lseek(fd1, (off_t)atoi(argv[1]), SEEK_SET) < 0)
    {
        fprintf(stderr, "lseek error\n");
        exit(1);
    }

    if(write(fd1, argv[2], strlen(argv[2])) < 0)
    {
        fprintf(stderr, "Write error\n");
        exit(0);
    }

    while((length = read(fd1, buf, BUFFER_SIZE)) > 0)
        write(fd1, buf, length);

    exit(0);

    
}