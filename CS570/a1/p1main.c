/** 
 * @author: Brian Gebel, Abhishek Choudhary
 * @username: masc0974, masc0980
 * @classInfo: CS570, Summer 2013
 * @Assignment # 1, Semaphores to manage a shared file
 * @filename: p1main.c
 *
 */

// Program includes
#include "p1.h"

/**
 * Initializes Program one
 */
int main() {
	// Initialize Local Variables
	int fileid;
	int pid;
	struct thread_args arguments;
    int i;    

	// Save pid to buffer
	pid = getpid();

	// Check if file exists and if it does delete it
	if (file_exists(FILENAME))
		unlink(FILENAME);

	// Open file for current processes if doesnt exist create it
	if((fileid = file_open(FILENAME)) < 0) {
		perror("File failed to open");
		exit(EXIT_FAILURE);
	}

	// Write the pid of the current process in the new file + carriage return and \n
	if(file_write(fileid, pid) < 0) {
		perror("File failed to write");
		exit(EXIT_FAILURE);
	}
	close(fileid);
	
	// Initialize semaphores
	if ((sem_init(&mutex, 0, 1)) < 0) {
		perror("Semaphore initialization error"); // Could not initialize mutex
		exit(EXIT_FAILURE);
	}

	// Populate thread arguments
	arguments.fd = fileid;

	// Create ten threads
    for (i = 0; i < MAXTHREADS; i++)
            pthread_create(&threads[i], NULL, thread_routine, (void *) &arguments);
    
    // wait for (join) all the threads 
    for (i = 0; i < MAXTHREADS; i++) 
            pthread_join(threads[i], NULL);

	// Exit with no errors
	exit(EXIT_SUCCESS);
	return 0;
}
