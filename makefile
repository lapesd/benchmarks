#
# Copyright(C) 2016 Pedro H. Penna <pedrohenriquepenna@gmail.com>
# 
# This file is part of LaPeSD Benchmarks.
# 
# LaPeSD Benchmarks is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by the
# Free Software Foundation; either version 3 of the License, or (at your
# option) any later version.
# 
# LaPeSD Benchmarks is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
# or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
# for more details.
# 
# You should have received a copy of the GNU General Public License along
# with LaPeSD Benchmarks. If not, see <http://www.gnu.org/licenses/>.
#

# Directories
BINDIR     = $(CURDIR)/bin
CONTRIBDIR = $(CURDIR)/contrib
INCDIR     = $(CURDIR)/include
SRCDIR     = $(CURDIR)/src

# Toochain.
CC=gcc

# Toolchain configuration.
CFLAGS   = -std=c99 -pedantic
CFLAGS  += -I $(INCDIR) -I $(CONTRIBDIR)/include
CFLAGS  += -Wall -Wextra -Werror
CFLAGS  += -O3
LDFLAGS += -fopenmp

# Common source files.
SRC = $(wildcard $(SRCDIR)/common/*.c)

# Common object files.
OBJ = $(SRC:.c=.o)

# Builds all kernels.
all: mm vp sequential

# Builds the MM kernel
mm: bindir $(OBJ)
	$(CC) $(CFLAGS) -D_SCHEDULE_STATIC_ $(SRCDIR)/mm/*.c $(OBJ) $(LDFLAGS) -o $(BINDIR)/mm.static
	$(CC) $(CFLAGS) -D_SCHEDULE_GUIDED_ $(SRCDIR)/mm/*.c $(OBJ) $(LDFLAGS) -o $(BINDIR)/mm.guided
	$(CC) $(CFLAGS) -D_SCHEDULE_DYNAMIC_ $(SRCDIR)/mm/*.c $(OBJ) $(LDFLAGS) -o $(BINDIR)/mm.dynamic

# Builds the VP kernel.
vp: bindir $(OBJ)
	$(CC) $(CFLAGS) $(SRCDIR)/vp/*.c $(OBJ) $(LDFLAGS) -o $(BINDIR)/vp

# Builds sequential kernels.
sequential:
	$(CC) $(CFLAGS) $(SRCDIR)/sequential/cmp.c $(OBJ) $(LDFLAGS) -o $(BINDIR)/cmp.seq
	$(CC) $(CFLAGS) $(SRCDIR)/sequential/fib.c $(OBJ) $(LDFLAGS) -o $(BINDIR)/fib.seq
	$(CC) $(CFLAGS) $(SRCDIR)/sequential/mm.c $(OBJ) $(LDFLAGS) -o $(BINDIR)/mm.seq
	$(CC) $(CFLAGS) $(SRCDIR)/sequential/prefix.c $(OBJ) $(LDFLAGS) -o $(BINDIR)/prefix.seq
	$(CC) $(CFLAGS) $(SRCDIR)/sequential/vp.c $(OBJ) $(LDFLAGS) -o $(BINDIR)/vp.seq

# Creates BINDIR
bindir:
	mkdir -p $(BINDIR)

# Builds an object file from a C source file.
%.o: %.c
	$(CC) $< $(CFLAGS) -c -o $@

# Cleans compilation files.
clean:
	rm -rf $(BINDIR)/*
	rm -rf $(OBJ)
