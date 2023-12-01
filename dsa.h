#ifndef _DSA_H_
#define _DSA_H_

#include <stdio.h>
#include <stdlib.h>

#define TRACKS 200
#define MIN_REQUESTS 50


void fcfs(int request_list[], int requested_list_size);
void sstf(int request_list[], int requested_list_size);
void scan(int request_list[], int requested_list_size);

#endif