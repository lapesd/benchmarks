CC=gcc
CFLAGS   = -std=c99 -pedantic -Wall -Wextra -Werror
CFLAGS  += -O3
LDFLAGS += -fopenmp

SRC = $(wildcard *.c)

EXEC = mm

all:
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(EXEC)

clean:
	rm -rf $(EXEC)


