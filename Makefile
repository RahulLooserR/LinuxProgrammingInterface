# -*- Makefile -*-
#  Makefile for building the code

DIRS = src 						\
	   20_signal_concept

# target for building codes in every subdirectories

all:
	@ for dir in ${DIRS}; do (cd $${dir}; ${MAKE}); done

# generating executables for all .c files in subdirectories
genex:
	@ for dir in ${DIRS}; do (cd $${dir}; ${MAKE} genex); done

# phony to specify that clean is target not a file
.PHONY: clean
clean:
	@ for dir in ${DIRS}; do (cd $${dir}; ${MAKE} clean); done
