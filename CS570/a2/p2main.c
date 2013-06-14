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
	int nframes, npages;
	int cfaults, lfaults, ofaults;
	char buffer[STORAGE];
	int parray[STORAGE];

	// Get the number of frames from user input
	printf("\nEnter number of frames: ");
	scanf("%d", nframes);


	// Check if file exists then continue with work else error out
	if (!file_exists(FILENAME)) {
		perror("File error");
		printf("Unable to found file or directory %s\n", FILENAME);
		printf("To generate input please run the cmd: make input\n");
		exit(EXIT_FAILURE);
	}
	
	// Open, read and close file save to buffer
	if (!file_read(FILENAME, buffer, STORAGE))
		perror("File error");

	// Create the page array based on buffer
	npages = int_array(buffer, parray);
	printf("%d\n", npages);

	// Execute testing
	cfaults = clock_replacement(parray, npages, nframes);
//	lfaults = line_replacement(parray, npages, nframes);
//	ofaults = optimal_replacement(parray, npages, nframes);

	// Output results
	printf("Total page faults for \"Clock\" algorithm: %d\n", cfaults);

	// Exit with no errors
	exit(EXIT_SUCCESS);
	return 0;
}
