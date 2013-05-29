########################################
## Makefile for Program 1
########################################

## Program executable name ##
PROGRAM = p1

## Make definitions ##
CC = gcc
#CFLAGS = -g

${PROGRAM}:	p1main.o
		${CC} -o ${PROGRAM} p1main.o

p1main.o:	p1.h
clean:
		rm -f *.o ${PROGRAM}
