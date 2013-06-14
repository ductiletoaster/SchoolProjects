/** 
 * @author: Brian Gebel, Abhishek Choudhary
 * @username: masc0974, masc0980
 * @classInfo: CS570, Summer 2013
 * @Assignment # 1, Semaphores to manage a shared file
 * @filename: p2algorithms.c
 *
 */

// Program includes
#include "p2.h"

/**
 * Clock page replacement algorithm
 */
int clock_replacement(int * parray, int psize, int nframes) {

	// Declare local variables
	int frame[1000] = {0};
	int usedbit[1000] = {0};
	int faultCount, i, j, k, m, flag;

	// Defining local variables
	faultCount = 0;
	m = 0;
	flag = 0;

	for(i=0; i < nframes-1; i++){                          //set all values in parray to zero
		frame[i] = 0;
		usedbit[i] = 0;
	}

	for(i = 0; i < psize; i++){
		while(1) {						//clock
			flag = 0;
			if(m > nframes-1)				//reset value after reaching end
				m = 0;

			for(k = 0;k < nframes; k++) {			//check if value is in clock
				if(frame[k] ==  parray[i]){
					usedbit[k] = 1;
					m = k;				//break at same value
					break;
				}
			}
			
			if(frame[m] == parray[i]) {			
				for(j = 0; j < nframes; j++){		
					if(frame[j] == 0){		//special case when page value is the same as frame value is introduced					m = j;
					m = j;				//before frames are filled. Set pointer to empty slot in clock	
					flag = 1;			//instead of setting pointer to same value.
					break;				
					}
				}
			}
			if(flag == 1)
				break;
		
			if(frame[m] == parray[i])			//break if values are the same
				break;

			if (usedbit[m] == 0) {				//If usedbit is zero then set page into frame
				frame[m] = parray[i];
				usedbit[m] = 1;
				faultCount++;
				m++;
				break;
			}

			else {				//else usedbit must equal one. Will iterate through until it reaches zero.
				usedbit[m] = 0;
				m++;
			}
		}
	}
	return faultCount;
}

/**
 * LRU (lowest replaceable unit) page replacement algorithm
 */
int line_replacement(int * pparray, int psize, int nframes) {
	return 0;
}

/**
 * Optimal page replacement algorithm
 */
int optimal_replacement(int * pparray, int psize, int nframes) {
	return 0;
}
