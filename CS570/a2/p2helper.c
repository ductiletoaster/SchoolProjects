/** 
 * @author: Brian Gebel, Abhishek Choudhary
 * @username: masc0974, masc0980
 * @classInfo: CS570, Summer 2013
 * @Assignment # 1, Semaphores to manage a shared file
 * @filename: p2helper.c
 *
 */

// Program includes
#include "p2.h"

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
int file_read(const char * filename, void * contents, size_t size) {
	// Declare local variables
	int fileid;
	char buffer[size];
	int length;

	 // Open file in readonly mode and save to buffer
	if (fileid = open(filename, O_RDONLY)) {
		if (lseek(fileid, 0, SEEK_SET) < 0) // Seek to begining 
			return FALSE;
		if (read(fileid, &buffer, size) < 0) // Read to buffer based on given size
			return FALSE;
		if (close(fileid) < 0) // Close file
			return FALSE;

		// Copy contents of buffer to our array
		strncpy(contents, buffer, size);
		return TRUE;
	}
	return FALSE;
}

/**
 * Converts char array into a integer array 
 */
int int_array(char * buffer, int * array) {

	// Declare local variables
	int poz;
	int count;
	int size;

	// Define local variables
    count = 0;

	// Get the length of buffer
	size = strlen(buffer);

    // Read each character and copy to in array
    while (sscanf(buffer,"%d%n",&array[count], &poz) == 1) {
        count++;
        buffer += poz;
        if (count >= size) 
        	break;
    }
    return count;
}
