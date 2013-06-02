/** 
 * @author: Brian Gebel
 * @version: 05.28.2013
 * @description: SDSU Summer 2013 CS570 Program 1
 *
 */

// Program includes
#include "p1.h"


/**
 * Discovers whether or not the file exists or not
 */
int file_exists(const char * filename) {
	struct stat buffer;
	return (stat(filename, &buffer) == 0); // Returns 0 if not found
}

//Thread function of opening the file and writing to it 
void *threadFunc(void *arg)
{
    // get the calling thread's ID 
    tid = pthread_self();
                
    return NULL;
}