/** 
 * @author: Brian Gebel, Abhishek Choudhary
 * @username: masc0974, masc0980
 * @classInfo: CS570, Summer 2013
 * @Assignment # 3, implement an interruptible clock and countdown timer
 * @filename: p3.h
 *
 */

// Program system includes
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>

// Syntax definitions
#define FALSE 0
#define TRUE 1

// Global definitions
#define DEFAULTTIME 6
#define NUMPIPES 2
#define STORAGE 32

// Included guard definition 
#ifndef P1_H_INCLUDED
#define P1_H_INCLUDED

int first_child(int, int, int);
int second_child(int, int, int);

#endif
