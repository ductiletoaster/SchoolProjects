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

	// Intialize Local Variables
	int fileid;
	int pid;

	// Check if file exists and if it doesnt creat it else open it up
	if (!file_exists(FILENAME)) {
		fileid = open(FILENAME, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR); // Create file for next processes
		close(fileid);
	} else {
		printf("%s\n", "READING");
	}

	// Write the pid of the current process in the new file + carriage return and \n
	pid = getpid();
	assert(fileid == open(FILENAME, O_RDWR)); // Open file for read/write
	lseek(fileid, 0, SEEK_SET);
	assert(sizeof(int) == write(fileid, &pid, sizeof(int)));
	
	// Close file
	close(fileid);

	// Intialize semaphores
	if ((sem_init(&mutex, 0, 1)) < 0)
		perror("Error"); // Could not initialize mutex

	// Create ten threads
	printf("%s\n", "Make threads");

	/* DO LOTS OF WORK WITH THREADS */


	// Exit with no errors
	exit(0);
}