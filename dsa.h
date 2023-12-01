#ifndef _DSA_H_
#define _DSA_H_

#include <stdio.h>
#include <stdlib.h>

#define TRACKS 200
#define MIN_REQUESTS 50


void fcfs(int request_list[], int , int fcfs_order[]);
void sstf(int request_list[], int requested_list_size, int sstf_order[]);
void scan(int request_list[], int requested_list_size, int scan_order[]);

#endif