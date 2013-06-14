/** 
 * @author: Brian Gebel, Abhishek Choudhary
 * @username: masc0974, masc0980
 * @classInfo: CS570, Summer 2013
 * @Assignment # 1, Semaphores to manage a shared file
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
#define STORAGE 1024

// Included guard definition 
#ifndef P1_H_INCLUDED
#define P1_H_INCLUDED

// Custom function declarations
int file_exists(const char *);
int file_read(const char *, void *, size_t);

#endif
