/** 
 * @author: Brian Gebel
 * @version: 05.28.2013
 * @description: SDSU Summer 2013 CS570 Program 1
 *
 */

// Program includes
#include "p1.h"

/**
 * Thread function of opening the file and writing to it 
 */
void * thread_routine(void *args) {
	// Intialize local variables
	int fileid;
	pthread_t tid;
	int i;

	// Thread arguments
	struct thread_args *arguments = args;
	fileid = arguments->fd;

    // Get the calling thread's ID
    tid = pthread_self();

    // Each thread executes MAXWRITES time
    for (i = 0; i < MAXWRITES; i++) {

		// Request a lock on mutex
		if(sem_wait(&mutex) < 0) { 
			perror("Semaphore wait failed"); // Could not get lock on mutex
			exit(EXIT_FAILURE);
		}

		/* ENTER CRITICAL ZONE */

    	if((fileid = file_open(FILENAME)) < 0) {
			perror("File failed to open");
			exit(EXIT_FAILURE);
		}

	    // Write the thread id of the current thread to the existing file
		if(file_write(fileid, tid) < 0) {
			perror("File failed to write");
			exit(EXIT_FAILURE);
		}
		close(fileid);

		// Output thread id to std out
		printf("Thread %i is running\n", tid);

		/* EXIT CRITICAL ZONE */

		// Release hold on mutex
		if(sem_post(&mutex) < 0) {
			perror("Semaphore post failed"); // Could not release mutex
			exit(EXIT_FAILURE);	
		}

		sleep(SLEEPTIME);
	}

	// exit this thread 
    pthread_exit((void *)0);

    return NULL;
}
