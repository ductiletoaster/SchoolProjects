########################################
## Makefile for Program 1
########################################

## Program executable name ##
PROGRAM = sem

## Make definitions ##
CC = gcc -g -Wall -pthread
SOURCE = p1main.o p1helper.o


${PROGRAM}:	${SOURCE}
		${CC} ${SOURCE} -o ${PROGRAM}

p1main.o:	p1main.c p1.h
	gcc -c p1main.c

p1helper.o:	p1helper.c p1.h
	gcc -c p1helper.c

clean:
		rm -f *.o ${PROGRAM} PROCTAB.txt
