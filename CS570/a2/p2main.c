/** 
 * @author: Brian Gebel, Abhishek Choudhary
 * @username: masc0974, masc0980
 * @classInfo: CS570, Summer 2013
 * @Assignment # 1, Semaphores to manage a shared file
 * @filename: p2main.c
 *
 */

// Program includes
#include "p2.h"

/**
 * Initializes Program one
 */
int main() {
	// Initialize Local Variables
	int pcount;
	char pstorage[STORAGE]; // Character reprecentation of pages

	// Get the number of frames from user input

	printf("\nEnter number of frames: ");
	scanf("%d", pcount);


	// Check if file exists then continue with work else error out
	if (!file_exists(FILENAME)) {
		perror("File error");
		printf("Unable to found file or directory %s\n", FILENAME);
		printf("To generate input please run the cmd: make input\n");
		exit(EXIT_FAILURE);
	}
	
	// Open, read and close file save to buffer
	if (!file_read(FILENAME, &pstorage, STORAGE))
		perror("File error");

	printf("%s\n", pstorage);

	// Exit with no errors
	exit(EXIT_SUCCESS);
	return 0;
}
