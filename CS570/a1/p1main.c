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

	int bufsize;
	char buffer[STORAGE];

	// Get current process pid
	pid = getpid();

	// Check if file exists and if it does delete it
	if (file_exists(FILENAME))
		unlink(FILENAME);

	// Create file for current processes
	if((fileid = open(FILENAME, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR)) < 0) {
		perror("File error");
		exit(EXIT_FAILURE);
	}

	// Save to buffer
	bufsize = sprintf(buffer, "%d\n", pid);

	// Write the pid of the current process in the new file + carriage return and \n
	lseek(fileid, 0, SEEK_SET);
	assert(bufsize == write(fileid, &buffer, bufsize));
	
	// Close file
	close(fileid);

	// Intialize semaphores
	if ((sem_init(&mutex, 0, 1)) < 0) {
		perror("Semaphore initialization error"); // Could not initialize mutex
		exit(EXIT_FAILURE);
	}

	// Create ten threads
	printf("%s\n", "Make threads");

	/* DO LOTS OF WORK WITH THREADS */


	// Exit with no errors
	exit(EXIT_SUCCESS);
}