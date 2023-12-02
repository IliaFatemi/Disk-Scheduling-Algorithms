#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dsa.h"
#include <assert.h>

void findMinTrackTest(){
    int arr1[6] = {1, 5, 3, 2, 6, 4};
    assert(findMinTrack(arr1, 0, 6) == 0);
    assert(findMinTrack(arr1, 1, 6) == 3);
    assert(findMinTrack(arr1, 2, 6) == 3);
    assert(findMinTrack(arr1, 3, 6) == 3);
    assert(findMinTrack(arr1, 4, 6) == 5);
    assert(findMinTrack(arr1, 5, 6) == 5);
    int arr2[6] = {1, 2, 3, 4, 5, 6};
    assert(findMinTrack(arr2, 0, 6) == 0);
    assert(findMinTrack(arr2, 1, 6) == 1);
    assert(findMinTrack(arr2, 2, 6) == 2);
    assert(findMinTrack(arr2, 3, 6) == 3);
    assert(findMinTrack(arr2, 4, 6) == 4);
    assert(findMinTrack(arr2, 5, 6) == 5);
}

void findIndexTrackTest(){
    int arr1[6] = {1, 5, 3, 2, 6, 4};
    assert(findIndexTrack(arr1, 1, 6) == 0);
    assert(findIndexTrack(arr1, 6, 6) == 4);
    assert(findIndexTrack(arr1, 4, 6) == 5);
    assert(findIndexTrack(arr1, 5, 6) == 1);
    assert(findIndexTrack(arr1, 3, 6) == 2);
    assert(findIndexTrack(arr1, 2, 6) == 3);
    int arr2[6] = {1, 2, 3, 4, 5, 6};
    assert(findIndexTrack(arr2, 1, 6) == 0);
    assert(findIndexTrack(arr2, 2, 6) == 1);
    assert(findIndexTrack(arr2, 3, 6) == 2);
    assert(findIndexTrack(arr2, 4, 6) == 3);
    assert(findIndexTrack(arr2, 5, 6) == 4);
    assert(findIndexTrack(arr2, 6, 6) == 5);
}

void sortTracksTest(){
    int arr1[6] = {1, 5, 3, 2, 6, 4};
    sortTracks(arr1, 6, false);
    assert(arr1[0] == 1);
    assert(arr1[1] == 2);
    assert(arr1[2] == 3);
    assert(arr1[3] == 4);
    assert(arr1[4] == 5);
    assert(arr1[5] == 6);
    sortTracks(arr1, 6, true);
    assert(arr1[0] == 6);
    assert(arr1[1] == 5);
    assert(arr1[2] == 4);
    assert(arr1[3] == 3);
    assert(arr1[4] == 2);
    assert(arr1[5] == 1);
}

void copyTracksTest(){
    int arr1[6] = {1, 2, 3, 4, 5, 6};
    int arr2[6];
    copyTracks(arr1, arr2, 6);
    assert(arr2[0] == 1);
    assert(arr2[1] == 2);
    assert(arr2[2] == 3);
    assert(arr2[3] == 4);
    assert(arr2[4] == 5);
    assert(arr2[5] == 6);
}

void runAllTests(){
    findMinTrackTest();
    findIndexTrackTest();
    sortTracksTest();
    copyTracksTest();
}

int main(int argc, char *argv[]){
    printf("Running tests...\n");
    runAllTests();
    printf("Done\n\n");


    int request_list[MIN_REQUESTS];
    int requested_list_size;
    char *arg = argv[1];
    char *ptr = arg;

    while (*ptr != '\0' && requested_list_size < MIN_REQUESTS) {
        // Extract integers separated by commas
        int track = strtol(ptr, &ptr, 10);
        if (ptr == arg || *ptr != ',' && *ptr != '\0') {
            printf("Invalid input format.\n");
            return 1;
        }
        request_list[requested_list_size++] = track;
        if (*ptr == ',') ptr++; // Move past the comma
    }

    int fcfs_order[requested_list_size], sstf_order[requested_list_size], scan_order[requested_list_size], c_scan_order[requested_list_size];

    sstf(request_list, requested_list_size, fcfs_order);
 
    return 0;
}