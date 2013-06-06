/** 
 * @author: Brian Gebel, Abhishek Choudhary
 * @username: masc0974, masc0980
 * @classInfo: CS570, Summer 2013
 * @Assignment # 1, Semaphores to manage a shared file
 * @filename: p1helper.c
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

/**
 * Open file and create file if it doesnt exist
 */
int file_open(const char * filename) {
	return open(filename, O_RDWR | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
}

/**
 * Write variables to file
 */
int file_write(int fd, int num) {
	// Intialize local variables
 	int bufsize;
	char buffer[STORAGE];

	// Save argument to buffer
	bufsize = snprintf(buffer, STORAGE, "%d\r\n", num);

	// Write buffer to end of file
	lseek(fd, 0, SEEK_SET);
	return write(fd, &buffer, bufsize);
}
