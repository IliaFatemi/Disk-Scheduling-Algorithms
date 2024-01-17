# Disk Scheduling Algorithms Implementation

This repository contains a comprehensive implementation of various disk scheduling algorithms in C, designed to optimize and compare the efficiency of disk head movement. Disk scheduling is crucial in operating systems to minimize the total seek time of a hard drive's read/write head. The algorithms implemented here include Shortest Seek Time First (SSTF), SCAN, Circular SCAN (CSCAN), and a function to compare their performance. 

## Features
- **SSTF Algorithm:** Minimizes the seek time by moving to the closest track not yet serviced.
- **SCAN Algorithm:** Moves the head towards one end of the disk, servicing requests along the way, then reverses direction at the end.
- **CSCAN Algorithm:** Similar to SCAN, but instead of reversing direction, it jumps to the other end of the disk.
- **Comparison Function:** Compares the performance of different algorithms based on total traversal and task execution delays.

## Usage
1. **Initialize Request List:** Create a list of track numbers to be serviced.
2. **Call Desired Algorithm:** Choose and call one of the disk scheduling algorithms (SSTF, SCAN, or CSCAN) with the request list.
3. **Observe Results:** The chosen algorithm will process the request list and provide the order of serviced tracks, total traversal distance, and task execution delays.
4. **Compare Algorithms:** Optionally, compare the performance of different algorithms using the comparison function.
