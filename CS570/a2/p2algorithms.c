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
int clock_replacement(int * parray, int npages, int nframes) {

	// Constants
	const int size = npages * nframes;

	// Declare local variables
	int frame[size];
	int usedbit[size];
	int nfaults, flag, i, j, k, m;

	// Defining local variables
	nfaults = 0;
	flag = 0;
	m = 0;

	// Initialize all elements to 0
	for(i = 0; i < size; i++) {
		frame[i] = 0;
		usedbit[i] = 0;
	}

	// Clock replacement alg
	for (i = 0; i < npages; i++) {
		while (TRUE) {
			flag = 0;

			// Reset value after reaching end
			if (m > nframes - 1)
				m = 0;
			
			// Check if value is in clock
			for (k = 0; k < nframes; k++) {
				if (frame[k] ==  parray[i]) {
					usedbit[k] = 1;
					m = k;
					break;
				}
			}
			
			if (frame[m] == parray[i]) {			
				for (j = 0; j < nframes; j++) {		
					if (frame[j] == 0) { // Special case when page value is the same as frame value is introduced
						m = j;	// Before frames are filled. Set pointer to empty slot in clock	
						flag = 1;	// Instead of setting pointer to same value.
						break;				
					}
				}
			}

			if (flag == 1)
				break;
		
			// Break if values are the same
			if (frame[m] == parray[i])			
				break;

			// If usedbit is zero then set page into frame
			if (usedbit[m] == 0) {				
				frame[m] = parray[i];
				usedbit[m] = 1;
				nfaults++;
				m++;
				break;
			}

			// Else usedbit must equal one. Will iterate through until it reaches zero.
			else {				
				usedbit[m] = 0;
				m++;
			}
		}
	}
	return nfaults;
}

/**
 * LRU (lowest replaceable unit) page replacement algorithm
 */
int line_replacement(int * parray, int npages, int nframes) {

	// Constants
	const int size = npages * nframes;

	// Declare local variables
	int frame[size];
	int b[npages], w[npages];
	int nfaults, a, i, k, m, j, g, t;

	// Defining local variables
	nfaults = 0;
	a = 0; 

	// Set all values to zero
	for(i = 0; i < size; i++)
		frame[i] = 0;

	// Copy first value into frame
	frame[0] = parray[a++];
	nfaults++;

	for (m = 1; m < npages; m++) {
		k = 0;

		for (g = 0; g < nframes; g++) {
			if (parray[m] != frame[g]) //see if the page value is not in frame.
			k++;
		}

		if (k == nframes) {	//if k == nframes then page value was not found in frames.		
			nfaults++;
			if (a < nframes) {		//If frames are not populated place in empty space
				frame[a] = parray[m];
				a++;

			}
			else {
				for (j = 0; j < nframes; j++) {
					w[j] = 0;
					for (g = m-1; g < npages; g--) {		//iterate downward on parray
						if (frame[j] != parray[g])	//If the frame is not equal to page then add one in
							w[j]++;			//parray w. This counts for lack of frequency.
						else	
							break;			//stop at value in frame that is the same as page
					}
				}

				for (j = 0; j < nframes; j++)			//copying parray b to parray w
					b[j] = w[j];

				for (j = 0; j < nframes; j++) {
					for(g = j; g < nframes; g++) {	

						if (b[j] < b[g]) {		//organizing frequncy of frames in ascending order where zero
							t = b[j];		//is most frequent
							b[j] = b[g];
							b[g] = t;
						}
					}
				}

				for (j = 0; j < nframes; j++) {
					if (w[j] == b[0])
						frame[j] = parray[m];
				}

			}
		}
	}
	return nfaults;
}

/**
 * Optimal page replacement algorithm
 */
int optimal_replacement(int * parray, int npages, int nframes) {

	// Constants
	const int size = npages * nframes;

	int frame[size];
	int lg[size];
	int m, index, i, j ,k , f, nfaults, fl0, fl1;

	// Defining local variables
	f = 0;
	nfaults = 0; 
	fl0 = 0; 
	fl1 = 0;

	// Set all array values before executing
	for (i = 0; i < size; i++) {
		frame[i] = -1;
		lg[i] = 0;			
	}

	for (j = 0; j < npages; j++) {	
		fl0 = 0; //set flags to zero
		fl1 = 0;

		for (i = 0; i < nframes; i++) {
			if (frame[i] == parray[j]) {	//check frames to see if it contains page.
				fl0 = 1;		//set flags to one if the same and then break.
				fl1 = 1;
				break;
			}
		}

		if (fl0 == 0) {
			for (i = 0; i < nframes; i++) {
				if (frame[i] == -1) {		//If frame is -1 then the frame is not full.
					frame[i] = parray[j];	//place page into frame
					fl1 = 1;			//set flag 1 to 1
					nfaults++;		//increment fault Count
					break;
				}
			}
		}

		if (fl1 == 0) {
			for (i = 0; i < nframes; i++)	
				lg[i]=0;

			for (i = 0; i < nframes; i++) {		//Checks to see if any of the frames are
				for (k = j + 1; k < npages; k++) {		//used later on in the Pages.
					if (frame[i] == parray[k]) {	//if the frame is used in the future then
						lg[i] = k - j;	//find the distance between the two and place it into lg[i]
						break;		//break out of loop
					}
				}
			}

			f = 0;
			for (i = 0; i < nframes; i++) {

				if (lg[i] == 0) {			//if frame was not used in future then set pointer to that point
					index = i;		//to be replaced later.
					f = 1;
					break;
				}
			}

			if (f == 0){				
				m = lg[0];
				index = 0;
				for (i = 1; i < nframes; i++) {
					if (m < lg[i]) {		//finding frame that is repeated furthest away in the page.
						m = lg[i];
						index = i;
					}
				}
			}
			frame[index] = parray[j];				//place page into frame
			nfaults++;					//increment fault count
		}
	}
	return nfaults;
}
