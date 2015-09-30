# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
# -g adds debugging information to the executable file
# -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall

# the build target executable:
TARGET = queue_test

all: $(TARGET)

SRCS = \
	$(TARGET).c \
	sdt_queue.c

$(TARGET):
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	$(RM) $(TARGET)