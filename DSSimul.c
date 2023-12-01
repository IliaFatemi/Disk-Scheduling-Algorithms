#include <stdio.h>
#include <stdlib.h>
#include "dsa.h"

int main(int argc, char *argv[]){
    printf("%s\n", argv[1]);
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


    return 0;
}