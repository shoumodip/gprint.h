CFLAGS = -Wall -Wextra -std=c11 -pedantic -I..

.PHONY: all
all: simple user_defined_types

simple: simple.c ../gprint.h
	cc ${CFLAGS} -o simple simple.c

user_defined_types: user_defined_types.c ../gprint.h
	cc ${CFLAGS} -o user_defined_types user_defined_types.c
