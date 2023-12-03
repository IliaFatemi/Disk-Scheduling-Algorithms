#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dsa.h"
#include "unitTests.h"

int main(int argc, char *argv[]){

    // Displaying a message for running unit tests
    printf("\nRunning unit tests: ");
    runAllTests();
    printf(COLOR_GREEN"Successful"COLOR_RESET"\n\n");

    
    // Retrieving command line arguments or generating random numbers for FCFS order
    int fcfs_order[MIN_REQUESTS];
    int requested_list_size;

    if(argc > 1){
        char *arg = argv[1];
        char *ptr = arg;

        while (*ptr != '\0' && requested_list_size < MIN_REQUESTS) {
            // Extract integers separated by commas
            int track = strtol(ptr, &ptr, 10);
            if (ptr == arg || *ptr != ',' && *ptr != '\0') {
                printf("Invalid input format.\n");
                return 1;
            }
            fcfs_order[requested_list_size++] = track;
            if (*ptr == ',') ptr++; // Move past the comma
        }
    }else{
        generateRandomNum(fcfs_order);
        requested_list_size = MIN_REQUESTS;
    }

    // Arrays to store order for different scheduling algorithms
    int sstf_order[requested_list_size], scan_order[requested_list_size], cscan_order[requested_list_size];

    // Running all algorithms 
    sstf(fcfs_order, requested_list_size, sstf_order);
    scan(fcfs_order, requested_list_size, scan_order);
    cscan(fcfs_order, requested_list_size, cscan_order);
    
    // Comparing FCFS with SSTF algorithm
    printf(COLOR_RED "\nFCFS " COLOR_RESET "VS." COLOR_GREEN" SSTF\n" COLOR_RESET);
    compare(fcfs_order, sstf_order, requested_list_size, FCFS, SSTF);

    // Comparing FCFS with SCAN algorithm
    printf(COLOR_RED "\nFCFS " COLOR_RESET "VS." COLOR_GREEN" SCAN\n" COLOR_RESET);
    compare(fcfs_order, scan_order, requested_list_size, FCFS, SCAN);

    // Comparing FCFS with CSCAN algorithm
    printf(COLOR_RED "\nFCFS " COLOR_RESET "VS." COLOR_GREEN" CSCAN\n" COLOR_RESET);
    compare(fcfs_order, cscan_order, requested_list_size, FCFS, CSCAN);

    // Comparing SCAN with CSCAN algorithm
    printf(COLOR_RED "\nSCAN " COLOR_RESET "VS." COLOR_GREEN" CSCAN\n" COLOR_RESET);
    compare(scan_order, cscan_order, requested_list_size, SCAN, CSCAN);
 
    return 0;
}