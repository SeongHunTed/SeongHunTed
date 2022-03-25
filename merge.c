#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[])
{
    char buf[BUFFER_SIZE];
    int fd1, fd2, fd3;
    int length;

    if(argc != 4)
    {
        fprintf(stderr, "Usage : %s <file1_in> <file_in2> <file_out>", argv[0]);
        exit(1);
    }

    if(fd1 = open(argv[1], O_RDWR) < 0)
    {
        fprintf(stderr, "open error for %s\n", argv[1]);
        exit(1);
    }

    if(fd2 = open(argv[2], O_RDWR) < 0)
    {
        fprintf("stderr, open error for %s\n", argv[2]);
        exit(1);
    }

    if(lseek(fd3, (off_t)0, SEEK_END) < 0)
    {
        fprintf(stderr, "lseek error\n");
        exit(1);
    }

    while((length = read(fd3, buf, BUFFER_SIZE)) > 0 )
    {
        write(fd3, buf, length);
    }

    exit(0);

}