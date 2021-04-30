#
# This file is part of the Fibonacci-X distribution (https://github.com/wmthornton/Fibonacci-X).
# Copyright (c) 2021 Wayne Michael Thornton aka DextersLaboratory2020.
# 
# This program is free software: you can redistribute it and/or modify  
# it under the terms of the GNU General Public License as published by  
# the Free Software Foundation, version 3.
#
# This program is distributed in the hope that it will be useful, but 
# WITHOUT ANY WARRANTY; without even the implied warranty of 
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License 
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#

# Makefile for generating Fibonacci-X (fib) executable
 
# *****************************************************
# Variables to control Makefile operation
# We are using g++ as the code for this project is in C++
# Compiler flags:
# -g    - this flag adds debugging information to the executable file
# -Wall - this flag is used to turn on most compiler warnings
 
CC = g++
CFLAGS = -Wall -g

# These variables are linked to the Linux root filesystem
DESTDIR = $#/bin
EXECDIR = $#/bin/fib
TMPDIR  = $#/root/Desktop/.fib

# These variables are linked to the Applications directory of the macOS filesystem.
MACDESTDIR = /opt/local/bin
MACEXECDIR = /opt/local/bin/fib
MACEXEC = /opt/local/bin/fib
MACTMPDIR = /opt/local/bin/.fib

#******************************************************
# We run make all to compile both Linux and macOS versions

all: nix mac
#******************************************************
# The executable target can be written very simply

nix: colors.h fib.cpp
	$(CC) $(CFLAGS) fib.cpp -o fib

#******************************************************
# The Macintosh executable target can be written very simply as well

mac: colors.h fib.cpp
	$(CC) $(CFLAGS) fib.cpp -o fib

# We install the executable to the /bin directory in the root of the filesystem. Normally this
# can only be written to by the root user or someone using sudo. After this command is run, any system
# user can simply type sbo into the terminal to start the executable as it will be in the user's $PATH
install: nix
	sudo mkdir -p ${DESTDIR}
	sudo cp fib ${DESTDIR}
	sudo mkdir -p ${TMPDIR}

remove: 
	sudo rm fib
	sudo rm -r ${EXECDIR}
	sudo rm -r ${TMPDIR}

clean:
	sudo rm fib
	sudo rm -r ${TMPDIR}
	sudo mkdir -p ${TMPDIR}

# Installing the executable to the opt/local/bin folder on macOS systems is a little more tricky.
install-mac: mac
	sudo mkdir -p ${MACDESTDIR}
	sudo cp fib ${MACDESTDIR}
	sudo mkdir -p ${MACTMPDIR}
	sudo chmod +x ${MACEXEC}

	

remove-mac:
	sudo rm fib
	sudo rm -r ${MACEXECDIR}
	sudo rm -r ${MACTMPDIR}

clean-mac:
	sudo rm fib
	sudo rm -r ${MACTMPDIR}
	sudo mkdir -p ${MACTMPDIR}