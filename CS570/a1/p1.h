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
#include <semaphore.h>
#include <pthread.h>

// Included guard definition 
#ifndef P1_H_INCLUDED
#define P1_H_INCLUDED

// Global access semaphore
sem_t mutex;

// Custom function declarations
int file_exists(const char *);

#endif