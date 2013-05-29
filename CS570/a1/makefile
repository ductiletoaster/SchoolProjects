PROGRAM = prog1
COMPILER = gcc

${PROGRAM}:	${PROGRAM}.o
		${COMPILER} ${PROGRAM}.o -o ${PROGRAM}

${PROGRAM}.o:	${PROGRAM}.h

clean:
		rm -f *.o ${PROGRAM}

lint:
		lint ${PROGRAM}.c
