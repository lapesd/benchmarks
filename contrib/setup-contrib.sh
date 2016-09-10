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

tar -xjvf papi-5.4.3.tar.bz2
cd papi-5.4.3/src
./configure --prefix=$PWD/../../
make
make install
cd ../../
rm -rf papi-5.4.3
