/** 
 * @author: Brian Gebel, Abhishek Choudhary
 * @username: masc0974, masc0980
 * @classInfo: CS570, Summer 2013
 * @Assignment # 3, implement an interruptible clock and countdown timer
 * @filename: p3helper.c
 *
 */

// Program includes
#include "p3.h"

/**
 * Routine to be executed by first child process
 */
int first_child(int stime, int filed1, int filed2) {

	// Initialize storage structures
	char buffer[STORAGE];
	struct tm* info;

	// System timer
	time_t timer;

	// Loop forever
	while(TRUE) {
		
		close(filed2); // Close writing in pipe
		read(filed1, &stime, sizeof(stime)); // Read in from second child
		time(&timer);

		// Output local time
		info = localtime(&timer);
		strftime(buffer, 25, "%H:%M:%S", info);
		printf("\nFirst Child-> %s\n" , buffer);
		if(stime == 1) 
			break;
		sleep(1);
	}

	// Close file descriptors for pipe
	close(filed1);
	close(filed2);

	return stime;
}

/**
 * Routine to be executed by second child process
 */
int second_child(int stime, int filed1, int filed2) {
	// Loop until seconds hits 0 time
	while (stime > 0) {
		// Second child work
		sleep(1);
		close(filed1); // Close reading in pipe
		write(filed2, &stime, sizeof(stime)); // Write to file descriptor pipe

		// Output remaing time and decrement
		printf("Second Child Time Left-> %d\n", stime);
		stime--;
	}

	// Close file descriptors for pipe
	close(filed1);
	close(filed2);

	return stime;
}
