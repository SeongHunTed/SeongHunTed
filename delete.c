#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    int fd;
    off_t end, cur;
    int length;
    int count = 0;
    char* buf;
    int stat = 0;

    if(argc != 4)
    {
        fprintf(stderr, "Usage : %s <offset> <byte> <file>\n");
        exit(1);
    }

    if((fd = open(argv[3], O_RDWR)) < 0)
    {
        fprintf(stderr, "open error for %s\n", argv[3]);
        exit(1);
    }

    end = (off_t)lseek(fd, (off_t)0, SEEK_END);

    if((cur = lseek(fd, (off_t)(atoi(argv[1]) + atoi(argv[2])), SEEK_SET)) < 0)
    {
        fprintf(stderr, "lseek error\n");
        exit(1);
    }

    buf = (char *)calloc((int)(end - cur + 1), sizeof(char));

    if(read(fd, buf, (int)(end - cur +1)) < 0)
    {
        if(cur > end)
        {
            fprintf(stderr, "read error\n");
            exit(1);
        } else stat = 1;
    } 

    lseek(fd, (off_t)atoi(argv[1]), SEEK_SET);

    if(stat == 0)
        wrtie(fd, buf, strlen(buf));
    free(buf);
    buf = (char*)calloc(length, sizeof(char));
    length = (int)lseek(fd, 0, SEEK_CUR);
    lseek(fd, (off_t)0, SEEK_SET);
    if(stat == 0)
        read(fd, buf, length);
    else read(fd, buf, atoi(argv[1]));

    fd = open(argv[3], O_WRONLY | O_TRUNC);
    lseek(fd, (off_t)0, SEEK_SET);
    write(fd, buf, length);
    exit(0);

}