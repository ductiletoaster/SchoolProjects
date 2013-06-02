/** 
 * @author: Brian Gebel
 * @version: 05.28.2013
 * @description: SDSU Summer 2013 CS570 Program 1
 *
 */

// Program includes
#include "p1.h"


/**
 * Discovers whether or not the file exsits or not
 */
int file_exists(const char * filename) {
	struct stat buffer;
	return (stat(filename, &buffer) == 0); // Returns 0 if not found
}