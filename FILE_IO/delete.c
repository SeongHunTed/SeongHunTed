#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char* argv[])
{
    int fd1;
    off_t end, cur;
    int length;
    char* buf1;
    char* buf2;

    if(argc != 4)
    {
        fprintf(stderr, "Usage : %s <offset> <byte> <file>\n", argv[0]);
        exit(1);
    }

    if((fd1 = open(argv[3], O_RDWR)) < 0)
    {
        fprintf(stderr, "open error for %s\n", argv[3]);
        exit(1);
    }

    end = (off_t)lseek(fd1, (off_t)0, SEEK_END);

    if((cur = lseek(fd1, (off_t)(atoi(argv[1]) + atoi(argv[2])), SEEK_SET)) < 0)
    {
        fprintf(stderr, "lseek error\n");
        exit(1);
    }

    // data 입력값 음수인 경우
    if(cur < atoi(argv[1]))
    {
        buf1 = (char *)calloc((int)(end - atoi(argv[1]) + 1), sizeof(char));
        lseek(fd1, (off_t)atoi(argv[1]), SEEK_SET);
        read(fd1, buf1, (int)(end - atoi(argv[1] + 1)));

        length = (int)lseek(fd1, cur, SEEK_SET);

        buf2 = (char *)calloc(length, sizeof(char));

        lseek(fd1, (off_t)0, SEEK_SET);

        read(fd1, buf2, length);

        fd1 = open(argv[3], O_WRONLY | O_TRUNC);
        lseek(fd1, (off_t)0, SEEK_SET);
        write(fd1, buf2, length);
        write(fd1, buf1, strlen(buf1));
        exit(0);
    }

    // data 입력값 양수인 경우
    if(cur > atoi(argv[1]))
    {
        buf1 = (char *)calloc((int)(end - cur + 1), sizeof(char));
        lseek(fd1, cur, SEEK_SET); 
        read(fd1, buf1, (int)(end - cur + 1));
        
        length = (int)lseek(fd1, (off_t)atoi(argv[1]), SEEK_SET);

        buf2 = (char*)calloc(length, sizeof(char));

        lseek(fd1, (off_t)0, SEEK_SET);

        read(fd1, buf2, length);

        fd1 = open(argv[3], O_WRONLY | O_TRUNC);
        lseek(fd1, (off_t)0, SEEK_SET);
        write(fd1, buf2, length);
        write(fd1, buf1, strlen(buf1));
        exit(0);
    }
}