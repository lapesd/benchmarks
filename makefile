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
BINDIR = $(CURDIR)/bin
INCDIR = $(CURDIR)/include
SRCDIR = $(CURDIR)/src

# Toochain.
CC=gcc

# Toolchain configuration.
CFLAGS   = -std=c99 -pedantic
CFLAGS  += -Wall -Wextra -Werror
CFLAGS  += -O3
LDFLAGS += -fopenmp

# Builds all kernels.
all: mm

# Builds the MM kernel
mm: bindir
	$(CC) $(CFLAGS) $(SRCDIR)/mm/*.c $(LDFLAGS) -o $(BINDIR)/mm

# Creates BINDIR
bindir:
	mkdir -p $(BINDIR)

# Cleans compilation files.
clean:
	rm -rf $(BINDIR)/*
