/** 
 * @author: Brian Gebel, Abhishek Choudhary
 * @username: masc0974, masc0980
 * @classInfo: CS570, Summer 2013
 * @Assignment # 2, Page replacement algorithms
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

	// Clock replacement algorithm
	for (i = 0; i < npages; i++) {
		while (TRUE) {
			flag = 0;

			// Reset the value after reaching end
			if (m > nframes - 1)
				m = 0;
			
			// Check if the value is in the clock
			for (k = 0; k < nframes; k++) {
				if (frame[k] ==  parray[i]) {
					usedbit[k] = 1;
					m = k;
					break;
				}
			}
			
			if (frame[m] == parray[i]) {			
				for (j = 0; j < nframes; j++) {		
					// The special case when the page value is the same as frame value introduced
					if (frame[j] == 0) { 
						m = j;	// Set pointer to empty slot in the clock before frames are filled. 
						flag = 1; // Alternative to setting pointer to the same value.
						break;				
					}
				}
			}

			if (flag == 1)
				break;
		
			// Break if values are same
			if (frame[m] == parray[i])			
				break;

			// Page is set in the frame if the used bit = 0
			if (usedbit[m] == 0) {				
				frame[m] = parray[i];
				usedbit[m] = 1;
				nfaults++;
				m++;
				break;
			}

			// Used bit = 1 otherwise. Will iterate through until it reaches zero.
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
			// See if the page value is not in frame.
			if (parray[m] != frame[g]) 
			k++;
		}

		// The page value was not foung if k == nframes
		if (k == nframes) {	
			nfaults++;
			// If frames are not populated place in empty space
			if (a < nframes) {		
				frame[a] = parray[m];
				a++;

			}
			else {
				for (j = 0; j < nframes; j++) {
					w[j] = 0;
					// Iterate downward on parray
					for (g = m-1; g < npages; g--) {		
						//If the frame != page, then add one in parray w. This is for lack of frequency
						if (frame[j] != parray[g])	
							w[j]++;			
						else       
							break;	// If value in frame is same as page,Stop.
					}
				}

				for (j = 0; j < nframes; j++)
					b[j] = w[j]; // Copying parray b to parray w

				for (j = 0; j < nframes; j++) {
					for(g = j; g < nframes; g++) {	

						// Organizing frequency of frames in ascending order where zero is most frequent
						if (b[j] < b[g]) {
							t = b[j];		
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
		fl0 = 0; // Set flags to zero
		fl1 = 0;

		for (i = 0; i < nframes; i++) {
			// Check the frames to see if it contains page. Set flags to the one if same and then break.
			if (frame[i] == parray[j]) {	
				fl0 = 1;		
				fl1 = 1;
				break;
			}
		}

		if (fl0 == 0) {
			for (i = 0; i < nframes; i++) {
                // If frame is -1, that means that the frame is not full.
				if (frame[i] == -1) {
					frame[i] = parray[j]; // Place page into frame
					fl1 = 1; // Set flag 1 to 1
					nfaults++; // Increment fault Count
					break;
				}
			}
		}

		if (fl1 == 0) {
			for (i = 0; i < nframes; i++)	
				lg[i]=0;
			
			// Checks to see if any of the frames are used later on in the Pages.
			for (i = 0; i < nframes; i++) {		
				for (k = j + 1; k < npages; k++) {		
					
					// If the frame is used in the future then find the distance between the two and put it into lg[i]
					if (frame[i] == parray[k]) {	
						lg[i] = k - j;
						break;		
					}
				}
			}

			f = 0;
			for (i = 0; i < nframes; i++) {

				if (lg[i] == 0) {			
					// If frame was not used in future, then the pinter is set to the point which is to be replaced later.
					index = i;
					f = 1;
					break;
				}
			}

			if (f == 0){				
				m = lg[0];
				index = 0;
				for (i = 1; i < nframes; i++) {
					// Search for the frame which is repeated furthest away in the page.
					if (m < lg[i]) {		
						m = lg[i];
						index = i;
					}
				}
			}
			// Place page into frame
			frame[index] = parray[j];		

			// Increment fault count
			nfaults++;					
		}
	}
	return nfaults;
}
