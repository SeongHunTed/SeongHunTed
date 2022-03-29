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

    if(argc < 4)
    {
        fprintf(stderr, "Usage : %s <offset> <readbyte> <filename>\n", argv[0]);
        exit(1);
    }

    if((fd = open(argv[3], O_RDONLY)) < 0)
    {
        fprintf(stderr, "open error for %s\n", argv[1]);
        exit(1);
    }

    // readbyte 음수인 경우
    if(atoi(argv[2]) < 0)
    {   
        if(lseek(fd, (off_t)(atoi(argv[1]) + atoi(argv[2])), SEEK_SET) < 0)
        {
            fprintf(stderr, "lseek error\n");
            exit(1);
        }
        buf = (char*)calloc(abs(atoi(argv[2])), sizeof(char));
        if((length = read(fd, buf, abs(atoi(argv[2])))) < 0)
            fprintf(stderr, "read error\n");
        else write(1, buf, length);
        exit(0);
    }   
    else // readbyte 양수인 경우
    {
        if(lseek(fd, (off_t)atoi(argv[1]), SEEK_SET) < 0)
        {
            fprintf(stderr, "lseek error\n");
            exit(1);
        }
        buf = (char*)calloc(atoi(argv[2]), sizeof(char));
        if((length = read(fd, buf, atoi(argv[2]))) < 0)
            fprintf(stderr, "read error\n");
        else write(1, buf, length);
        exit(0);
    }

    

    
}
