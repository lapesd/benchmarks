CC=gcc
CFLAGS   = -std=c99 -pedantic -Wall -Wextra -Werror
CFLAGS  += -O3
LDFLAGS += -fopenmp

SRC = $(wildcard *.c)

EXEC = mm

all: static guided dynamic

static:
	$(CC) $(CFLAGS) -D_SCHEDULE_STATIC_ $(SRC) $(LDFLAGS) -o $(EXEC).static

guided:
	$(CC) $(CFLAGS) -D_SCHEDULE_GUIDED_ $(SRC) $(LDFLAGS) -o $(EXEC).guided

dynamic:
	$(CC) $(CFLAGS) -D_SCHEDULE_DYNAMIC_ $(SRC) $(LDFLAGS) -o $(EXEC).dynamic

clean:
	rm -rf $(EXEC).*
