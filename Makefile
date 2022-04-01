CC = gcc
CFLAGS = -W -Wall
TARGET = fileio_exe
OBJECTS = copy.o read.o merge.o overwrite.o insert.o delete.o

all : $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm *.o fileio_exe

