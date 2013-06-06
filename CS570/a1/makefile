 
# @author: Brian Gebel, Abhishek Choudhary
# @username: masc0974, masc0980
# @classInfo: CS570, Summer 2013
# @Assignment # 1, Semaphores to manage a shared file
# @filename: makefile

########################################
## Makefile for Program 1
########################################

## Program executable name ##
PROGRAM = sem

## Make definitions ##
# -pthread maybe needed on linux machines
CC = gcc -g -Wall 
SOURCE = p1main.o p1thread.o p1helper.o


${PROGRAM}:	${SOURCE}
		${CC} -o ${PROGRAM} ${SOURCE} -lrt

p1main.o:	p1main.c p1.h
	gcc -c p1main.c

p1thread.o:	p1thread.c p1.h
	gcc -c p1thread.c

p1helper.o:	p1helper.c p1.h
	gcc -c p1helper.c

clean:
		rm -f *.o ${PROGRAM} PROCTAB.txt
