#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    int fd;
    char *buf;
    int length;

    printf("%s %s %s %s\n", argv[0], argv[1], argv[2], argv[3]);

    if(argc < 4)
    {
        fprintf(stderr, "Usage : %s filein offset readbyte\n", argv[0]);
        exit(1);
    }

    if((fd = open(argv[1], O_RDONLY)) < 0)
    {
        fprintf(stderr, "open error for %s\n", argv[1]);
        exit(1);
    }

    if(lseek(fd, (off_t)atoi(argv[2]), SEEK_SET) < 0)
    {
        fprintf(stderr, "lseek error\n");
        exit(1);
    }

    if(argv[3] < 0)
        fprintf(stderr, "readbyte error\n");
    else
    {
        buf = (char*)calloc(atoi(argv[3]), sizeof(char));
        if((length = read(fd, buf, atoi(argv[3]))) < 0)
            fprintf(stderr, "read error\n");
        else write(1, buf, length);
    }

    exit(0);

    
}
