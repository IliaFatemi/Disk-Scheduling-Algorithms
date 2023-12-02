#ifndef _DSA_H_
#define _DSA_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRACK_SIZE 200
#define MIN_REQUESTS 50


void sstf(int request_list[], int requested_list_size, int sstf_order[]);
void scan(int request_list[], int requested_list_size, int scan_order[]);

void print_task_order(int task[], int size);
void copyTracks(int source[], int destination[], int size);
int shortestDistance(int tracks[], int start, int end);
int findIndexTrack(int tracks[], int track, int size);
void compare(int requested_tracks[], int proccessed_tracks[], int size);
bool isInRequest(int tracks[], int track, int size);
#endif