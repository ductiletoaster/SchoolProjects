/** 
 * @author: Brian Gebel, Abhishek Choudhary
 * @username: masc0974, masc0980
 * @classInfo: CS570, Summer 2013
 * @Assignment # 1, Semaphores to manage a shared file
 * @filename: p1.h
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
#define FILENAME "PROCTAB.txt"
#define MAXWRITES 10
#define MAXTHREADS 10
#define SLEEPTIME 1
#define STORAGE 32

// Included guard definition 
#ifndef P1_H_INCLUDED
#define P1_H_INCLUDED

// Global access semaphore
sem_t mutex;

// Global Variables
pthread_t threads[MAXTHREADS];

// Thread specific functions
void * thread_routine(void *);

// Custom function declarations
int file_open(const char *);
int file_exists(const char *);
int file_write(int, int);

// Structure for thread routine arguments
struct thread_args {
    int fd;
};

#endif
