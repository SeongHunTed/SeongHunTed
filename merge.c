#include "fileio.h"

void merge(int argc, char* argv[])
{
    char buf[BUFFER_SIZE];
    int fd1, fd2, fd3;
    int length;

    if(argc != 4)
    {
        fprintf(stderr, "Usage : %s <file1_in1> <file_in2> <file_out>", argv[0]);
        exit(1);
    }
    
    if((fd1 = open(argv[1], O_RDWR)) < 0)
    {
        fprintf(stderr, "open error for %s\n", argv[1]);
        exit(1);
    }

    if((fd2 = open(argv[2], O_RDWR)) < 0)
    {
        fprintf(stderr, "open error for %s\n", argv[2]);
        exit(1);
    }

    if((fd3 = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, S_MODE)) < 0)
    {
        fprintf(stderr, "open error for %s\n", argv[3]);
        exit(1);
    }

    while((length = read(fd1, buf, BUFFER_SIZE)) > 0 )
    {
        write(fd3, buf, length);
    }
    while((length = read(fd2, buf, BUFFER_SIZE)) > 0 )
    {
        write(fd3, buf, length);
    }


    exit(0);
}
