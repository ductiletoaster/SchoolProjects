/** 
 * @author: Brian Gebel, Abhishek Choudhary
 * @username: masc0974, masc0980
 * @classInfo: CS570, Summer 2013
 * @Assignment # 2, Page replacement algorithms
 * @filename: p2.h
 *
 */

// Program system includes
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h> 
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <fcntl.h>
#include <assert.h>

// Syntax definitions
#define FALSE 0
#define TRUE 1

// Global definitions
#define FILENAME "pages.txt"
#define STORAGE 64

// Included guard definition 
#ifndef P1_H_INCLUDED
#define P1_H_INCLUDED

// Page replacement algorithms
int clock_replacement(int *, int, int);
int line_replacement(int *, int, int);
int optimal_replacement(int *, int, int);

// Custom function declarations
int file_exists(const char *);
int file_read(const char *, void *, size_t);
int int_array(char *, int *);

#endif
