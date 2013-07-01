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
	int status1 = 0; 
	int status2 = 0;
	int secondsInt; // default to 6 seconds
	time_t timer;
	char buffer[25];
	struct tm* tm_info;
	char *timeLeftStr;
	int fd[2];	//file descriptor for piping

	// Intialize pid variables for new children
	pid_t fchild;
	pid_t schild;

	if(pipe(fd)) {		// make pipe and check to see it opened correctly.
		perror("Pipe failed");
        exit(EXIT_FAILURE);
	}
	
	// Set variables to program arguments
	if (argc >= 2 )
		secondsInt = atoi(argv[1]);

	// Check time period is valid
	if (secondsInt > 1) {
		printf("Invalid Argument. Reverting to default of %d seconds", DEFAULTTIME);
		secondsInt = DEFAULTTIME;
	}
	
	printf("\nProgram allotted %d seconds:\n", secondsInt);
	printf("----------------------------------\n\n");

	fchild = fork(); // create first child
	
	if (fchild != 0) { //In parent process from first child
		
		printf("Parent doing work\n");	
		schild = fork(); //create second child
		waitpid(schild, &status2, 0);
		waitpid(fchild, &status1, 0);
	
		if (schild != 0){ //In parent process from second child
			printf("Back to parent from second child\n");
			exit(1);
		}
		else { //In second child
			while (secondsInt > 0){
				sleep(1);
				close(fd[0]); //Close reading in pipe
				write(fd[1], &secondsInt, sizeof(secondsInt)); //Write to file descriptor. Sending through pipe.
		
				printf("Second Child Time Left-> %d\n", secondsInt);
				secondsInt--;
			}
			close(fd[0]);
			close(fd[1]);
			exit(1);
		}
	}
	
	else { // in first child

		while(1) {
			
			close(fd[1]); //close writing in pipe
			read(fd[0], &secondsInt, sizeof(secondsInt)); // read in from second child.
			time(&timer);
			tm_info = localtime(&timer);
			strftime(buffer, 25, "%H:%M:%S", tm_info);
			printf("\nFirst Child-> %s\n" , buffer);
			if(secondsInt == 1) 
				break;	
			sleep(1);
		}
		close(fd[0]); //close pipe
		close(fd[1]); //close pipe
		exit(1);
	}

	// Exit with no errors
	exit(EXIT_SUCCESS);
	return 0;
}
