#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024
#define S_MODE 0644
#define BUFFER_SIZE_COPY 10

void copy();
void read();
void merge();
void overwrite();
void insert();
void delete();
