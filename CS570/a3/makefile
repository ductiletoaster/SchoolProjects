 
# @author: Brian Gebel, Abhishek Choudhary
# @username: masc0974, masc0980
# @classInfo: CS570, Summer 2013
# @Assignment # 3, implement an interruptible clock and countdown timer
# @filename: makefile

########################################
## Makefile for Program 1
########################################

## Program executable name ##
PROGRAM = a3

## Make definitions ##
# -pthread maybe needed on linux machines
CC = gcc -g -Wall 
SOURCE = p3main.o p3helper.o


${PROGRAM}:	${SOURCE}
		${CC} -o ${PROGRAM} ${SOURCE} -lrt

p2main.o:	p3main.c p3.h
	gcc -c p3main.c

p2helper.o:	p3helper.c p3.h
	gcc -c p3helper.c

clean:
		rm -f *.o ${PROGRAM}
