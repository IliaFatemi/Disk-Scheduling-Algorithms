#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dsa.h"
#include "unitTests.h"
#include <assert.h>

void ShortestDistanceTest(){
    int arr1[6] = {1, 5, 3, 2, 6, 4};
    assert(shortestDistance(arr1, 1, 6) == 3);
    arr1[0] = -1; 
    assert(shortestDistance(arr1, 2, 6) == 2);
    arr1[3] = -1;
    assert(shortestDistance(arr1, 3, 6) == 5);
    arr1[2] = -1;
    assert(shortestDistance(arr1, 4, 6) == 1);
    arr1[5] = -1;
    assert(shortestDistance(arr1, 5, 6) == 4);
    arr1[1] = -1;
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
    ShortestDistanceTest();
    findIndexTrackTest();
    copyTracksTest();
}