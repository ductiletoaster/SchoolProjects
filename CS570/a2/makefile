 
# @author: Brian Gebel, Abhishek Choudhary
# @username: masc0974, masc0980
# @classInfo: CS570, Summer 2013
# @Assignment # 2, Page replacement algorithms
# @filename: makefile

########################################
## Makefile for Program 1
########################################

## Program executable name ##
PROGRAM = a2

## Make definitions ##
# -pthread maybe needed on linux machines
CC = gcc -g -Wall 
SOURCE = p2main.o p2algorithms.o p2helper.o


${PROGRAM}:	${SOURCE}
		${CC} -o ${PROGRAM} ${SOURCE} -lrt

p2main.o:	p2main.c p2.h
	gcc -c p2main.c

p2algorithms.o:	p2algorithms.c p2.h
	gcc -c p2algorithms.c

p2helper.o:	p2helper.c p2.h
	gcc -c p2helper.c

input:
	echo "2 3 2 1 5 2 4 5 3 2 5 2\n\0" > pages.txt

clean:
		rm -f *.o ${PROGRAM} pages.txt
