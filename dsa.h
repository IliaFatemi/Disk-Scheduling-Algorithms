#ifndef _DSA_H_
#define _DSA_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TRACK_SIZE 200
#define MIN_REQUESTS 50

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_RESET   "\x1b[0m"

enum Algorithm {SSTF, SCAN, FCFS, CSCAN};

void sstf(int request_list[], int requested_list_size, int sstf_order[]);
void scan(int request_list[], int requested_list_size, int scan_order[]);
void cscan(int request_list[], int requested_list_size, int cscan_order[]);

void copyTracks(int source[], int destination[], int size);
int shortestDistance(int tracks[], int start, int end);
int findIndexTrack(int tracks[], int track, int size);
void compare(int requested_tracks[], int proccessed_tracks[], int size, enum Algorithm alg, enum Algorithm compareToAlg);
bool isInRequest(int tracks[], int track, int size);
void generateRandomNum(int requested_tracks[]);
int traversalTime(int track[], int size, enum Algorithm alg);
void print_task_order(int task[], int size);
void printDelaysStat(int requested_tracks[], int proccessed_tracks[], int size, bool print_delays);
#endif