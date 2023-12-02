#include "dsa.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to implement Scan algorithm
void sstf(int request_list[], int requested_list_size, int sstf_order[]) {
    int sstf_tracks[requested_list_size],
    readWrite_head = request_list[0],
    readWrite_head_index,
    num_processed_tracks = 0,
    total_distance_covered = 0;

    copyTracks(request_list, sstf_tracks, requested_list_size);
    sortTracks(sstf_tracks, requested_list_size, true);
    readWrite_head_index = findIndexTrack(sstf_tracks, readWrite_head, requested_list_size);

    for(int i = readWrite_head_index; i < requested_list_size; i++){
        sstf_order[num_processed_tracks] = sstf_tracks[i];
        num_processed_tracks++;
    }

    for(int i = readWrite_head_index-1; i >= 0; i--){
        sstf_order[num_processed_tracks] = sstf_tracks[i];
        num_processed_tracks++;
    }

    compare(request_list, sstf_order, requested_list_size);
}

void scan(int request_list[], int requested_list_size, int scan_order[]){
    int readWrite_head = request_list[0];
}

void sortTracks(int tracks[], int size, bool decending){
    if(decending){
        selectionSort(tracks, size);
    }else{
        int temp;
        for(int i = 0; i < size; i++){
            for(int j = i + 1; j< size; j++){
                if(tracks[i] > tracks[j]){
                    temp = tracks[i];
                    tracks[i] = tracks[j];
                    tracks[j] = temp;
                }
            }
        }
    }
}

int findIndexTrack(int tracks[], int track, int size){
    for (int i = 0; i < size; i++){
        if(tracks[i] == track){
            return i;
        }
    }
    return -1;
}

void copyTracks(int source[], int destination[], int size){
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

int findMinTrack(int tracks[], int start, int end){
    int min = tracks[start], index = start;
    while(start < end){
        if(min > tracks[start]){
            min = tracks[start];
            index = start;
        }
        start++;
    }
    return index;
}

void print_task_order(int task[], int size){
    printf("(");
    for(int i = 0; i < size; i++){
        if(i == size-1){
            printf("%d", task[i]);
        }else{
            printf("%d, ", task[i]);
        }
    }
    printf(")\n");
}

void compare(int requested_tracks[], int proccessed_tracks[], int size){
    printf("Requested Tasks sequence: ");
    print_task_order(requested_tracks, size);
    printf("Serviced Task sequence: ");
    print_task_order(proccessed_tracks, size);

    int delayed, sum = 0, num_delays = 0, longest_delay = 0, longest_delay_track = 0, total_traversal = 0;
    for(int i = 0; i < size; i++){
        delayed = findIndexTrack(proccessed_tracks, proccessed_tracks[i], size) - findIndexTrack(requested_tracks, proccessed_tracks[i], size);
        if(delayed <= 0){
            printf("Track %d: delayed by 0\n", proccessed_tracks[i]);
        }else{
            printf("Track %d: delayed by %d\n", proccessed_tracks[i], delayed);
            num_delays++;
            sum += delayed;
            if(delayed > longest_delay){
                longest_delay = delayed;
                longest_delay_track = proccessed_tracks[i];
            }
        }
    }

    printf("Total tracks traversed: %d\n", total_traversal);
    if(longest_delay == 0){
        printf("Longest delay: None\n");
    }else{
        printf("Longest delay: %d from track %d\n", longest_delay, longest_delay_track);
    }
    printf("Avg Delay time: %.2f\n", (double)(sum/num_delays));
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int tracks[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (tracks[j] > tracks[max_idx]) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            swap(&tracks[i], &tracks[max_idx]);
        }
    }
}