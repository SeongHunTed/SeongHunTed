#include "fileio.h"
void copy(int argc, char* argv[])
{
    char buf[BUFFER_SIZE] = {0};
    int fd1, fd2;
    int length;

    if(argc != 3)
    {
        fprintf(stderr, "Follow : %s <file_in> <file_out>", argv[0]);
        exit(1);
    }

    if((fd1 = open(argv[1], O_RDONLY)) < 0)
    {
        fprintf(stderr, "open error for %s\n", argv[1]);
        exit(1);
    }

    if((fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_MODE)) < 0)
    {
        fprintf(stderr, "open error for %s\n", argv[2]);
        exit(1);
    }
    while((length = read(fd1, buf, BUFFER_SIZE_COPY)) > 0)
        write(fd2, buf, length);
    exit(0);
}
