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
		perror("File failed to open");
		exit(EXIT_FAILURE);
	}

	// Save to buffer
	bufsize = sprintf(buffer, "%d\r\n", pid);

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


	// Request a lock on mute
	if(sem_wait(&mutex) < 0) { 
		perror("Semaphore wait failed"); // Could get lock on mutex
		exit(EXIT_FAILURE);
	}

	/* ENTER CRITICAL ZONE */


	/* EXIT CRITICAL ZONE */

	// Release hold on mutex
	if(sem_post(&mutex) < 0) {
		perror("Semaphore post failed"); // Could not release mutex
		exit(EXIT_FAILURE);	
	}

	// Exit with no errors
	exit(EXIT_SUCCESS);
}