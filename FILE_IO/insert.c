#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    int fd;
    off_t cur, end;
    char* buf;

    // 입력 인자
    if(argc != 4)
    {
        fprintf(stderr, "Usage : %s <offset> <data> <file>\n", argv[0]);
        exit(1);
    }

    // file open
    if((fd = open(argv[3], O_RDWR)) < 0)
    {
        fprintf(stderr, "open error for %s\n", argv[3]);
        exit(1);
    }

    end = (off_t)lseek(fd, (off_t)0, SEEK_END);

    // curser move
    if((cur = lseek(fd, (off_t)atoi(argv[1]), SEEK_SET)) < 0)
    {
        fprintf(stderr, "lseek error\n");
        exit(1);
    }

    buf = (char *)calloc((int)(end - cur +1), sizeof(char));

    if(read(fd, buf, (int)(end - cur + 1)) < 0)
    {
        if(cur < end)
        {
            fprintf(stderr, "read error for %s\n", argv[3]);
            exit(1);
        }
    }

    lseek(fd, cur, SEEK_SET);

    if(write(fd, argv[2], strlen(argv[2])) < 0)
    {
        fprintf(stderr, "write error for %s\n", argv[1]);
        exit(1);
    }

    //EOF에서 Append가 되는 것인가?
    write(fd, buf, strlen(buf));

    exit(0);
}