/** 
 * @author: Brian Gebel, Abhishek Choudhary
 * @username: masc0974, masc0980
 * @classInfo: CS570, Summer 2013
 * @Assignment # 3, implement an interruptible clock and countdown timer
 * @filename: p2main.c
 *
 */

// Program includes
#include "p3.h"

/**
 * Initializes Program three
 */
int main(int argc, char *argv[]) {
	
	// Initialize Local Variables
	int status1; 
	int status2;
	int seconds;

	// Pipe file descriptors
	int fd[NUMPIPES];

	// Intialize pid variables for new children
	pid_t fchild;
	pid_t schild;

	// Set variables 
	status1 = 0; 
	status2 = 0;

	if(pipe(fd)) { // Make pipe and check to see it opened correctly.
		perror("Pipe failed");
        exit(EXIT_FAILURE);
	}
	
	// Set variables to program arguments
	if (argc >= 2)
		seconds = atoi(argv[1]);

	// Check time period is valid
	if (seconds < 1) {
		printf("Invalid Argument. Reverting to default of %d seconds\n", DEFAULTTIME);
		seconds = DEFAULTTIME;
	}
	
	printf("\nProgram allotted %d seconds:\n", seconds);
	printf("-----------------------------\n\n");

	// Fork first child process
	if ((fchild = fork()) == -1) {
		perror("Fork failed");
        exit(EXIT_FAILURE);
	} 

	// Fork was a success and now parent has control
	if (fchild > 0) { 
		
		// Alert user to parent control
		printf("Parent doing work\n");	

		// Create second child process
		if ((schild = fork()) == -1) {
			perror("Fork failed");
	        exit(EXIT_FAILURE);
		}

		// Child in wait status
		waitpid(schild, &status2, 0);
		waitpid(fchild, &status1, 0);
	
		// In parent process from second child
		if (schild > 0) {
			printf("Back to parent from second child\n");
			exit(EXIT_SUCCESS);
		} else { 
			// Execute second childs routine
			seconds = second_child(seconds, fd[0], fd[1]);

			// Exit with no errors
			exit(EXIT_SUCCESS);
		}
	} else {

		// Execute second childs routine
		seconds = first_child(seconds, fd[0], fd[1]);

		// Exit with no errors
		exit(EXIT_SUCCESS);
	}

	// Exit with no errors
	exit(EXIT_SUCCESS);
	return 0;
}
