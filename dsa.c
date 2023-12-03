#include "dsa.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>


void sstf(int request_list[], int requested_list_size, int sstf_order[]) {
    int sstf_tracks[requested_list_size],
    readWrite_head = request_list[0],
    readWrite_head_index,
    num_processed_tracks = 0,
    total_distance_covered = 0,
    shortest_distance_neighbor_index = 0;

    copyTracks(request_list, sstf_tracks, requested_list_size);
    readWrite_head_index = findIndexTrack(sstf_tracks, readWrite_head, requested_list_size);

    while(num_processed_tracks < requested_list_size){
        sstf_order[num_processed_tracks] = sstf_tracks[readWrite_head_index];
        shortest_distance_neighbor_index = shortestDistance(sstf_tracks, sstf_tracks[readWrite_head_index], requested_list_size);
        sstf_tracks[readWrite_head_index] = -1;
        readWrite_head_index = shortest_distance_neighbor_index;
        num_processed_tracks++;
    }
}

void scan(int request_list[], int requested_list_size, int scan_order[]){
    int scan_tracks[requested_list_size],
    readWrite_head = request_list[0],
    num_processed_tracks = 0, 
    tracker = readWrite_head; 
    bool reverse_tracker = true;

    copyTracks(request_list, scan_tracks, requested_list_size);
    scan_order[num_processed_tracks] = readWrite_head;
    scan_tracks[num_processed_tracks] = -1;
    num_processed_tracks++;

    while (num_processed_tracks < requested_list_size){
        if(isInRequest(scan_tracks, tracker, requested_list_size)){
            scan_order[num_processed_tracks] = request_list[findIndexTrack(request_list, tracker, requested_list_size)];
            num_processed_tracks++;
        }
        if(reverse_tracker){
            tracker--;
        }else{
            tracker++;
        }
        if(tracker > TRACK_SIZE && reverse_tracker == false){
            reverse_tracker = true;
            tracker = TRACK_SIZE;
        }else if(tracker < 0 && reverse_tracker == true){
            tracker = 0;
            reverse_tracker = false;
        }
    }
}

bool isInRequest(int tracks[], int track, int size){
    for(int i = 0; i < size; i++){
        if(tracks[i] == track){
            tracks[i] = -1;
            return true;
        }
    }
    return false;
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

int shortestDistance(int tracks[], int start, int end){
    int min = __INT_MAX__, index = 0, pos = 0;
    while(index < end){
        if(tracks[index] != start && tracks[index] != -1 && abs(start-tracks[index]) < min){
            min = abs(start-tracks[index]);
            pos = index;
        }
        index++;
    }
    return pos;
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
    printf("\n");

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

    printf("\nTotal tracks traversed: %d\n", total_traversal);
    printf("Total delays: %d\n", num_delays);
    if(longest_delay == 0){
        printf("Longest delay: None\n");
    }else{
        printf("Longest delay: %d from track %d\n", longest_delay, longest_delay_track);
    }

    if(num_delays != 0){
        printf("Avg Delay time: %.2f\n", (double)(sum/num_delays));
    }else{
        printf("Avg Delay time: 0\n");
    }
}

void generateRandomNum(int requested_tracks[]){
        int i, j, num;
    srand(time(NULL)); // Seed the random number generator

    for (i = 0; i < MIN_REQUESTS; i++) {
        int exists;
        do {
            exists = 0;
            num = rand() % TRACK_SIZE; // Generate a random number in the range [0, 199]

            // Check if the number already exists in the list
            for (j = 0; j < i; j++) {
                if (requested_tracks[j] == num) {
                    exists = 1;
                    break;
                }
            }
        } while (exists); // Repeat until a unique number is found

        requested_tracks[i] = num; // Add the unique number to the list
    }

    printf("Generated List of Unique Random Integers:\n");
    for (i = 0; i < MIN_REQUESTS; i++) {
        printf("%d ", requested_tracks[i]);
    }
    printf("\n");
}