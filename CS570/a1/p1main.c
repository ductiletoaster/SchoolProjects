/** 
 * @author: Brian Gebel
 * @version: 05.28.2013
 * @description: SDSU Summer 2013 CS570 Program 1
 *
 */

// Program includes
#include "p1.h"

/**
 * Intializes Program one
 */
int main() {

	// Create file
	// Write the pid of the current process in the new file + carriage return and \n
	// Close file

	// Intialize semaphores
	if ((sem_init(&mutex, 0, 1)) < 0)
		perror("Error: Could not intialize semaphore");

	// Create ten threads
	printf("%s\n", "Make threads");

	/* DO LOTS OF WORK WITH THREADS */


	// Exit with no errors
	exit(0);
}