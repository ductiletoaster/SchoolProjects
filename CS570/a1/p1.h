/** 
 * @author: Brian Gebel
 * @version: 05.28.2013
 * @description: SDSU Summer 2013 CS570 Program 1
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
#define MAXTHREADS 10
#define STORAGE 32

// Included guard definition 
#ifndef P1_H_INCLUDED
#define P1_H_INCLUDED

// Global access semaphore
sem_t mutex;

// Global Variables
pthread_t  threads[MAXTHREADS];
pthread_mutex_t lock;
pthread_t tid;   // thread id

// Custom function declarations
int file_exists(const char *);
void * thread_fopen(void *);

#endif