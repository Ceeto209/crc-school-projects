// Name: Israel Vasquez
// Assignment#: A7
// File Name: quicksort.cpp
// Purpose: Implements partition function and recursive quickSortHelper
// Course: CISP 400 F24

#include "quicksort.h"

// Partition function for quicksort
int partition(std::vector<int>& vec, int low, int high) {
    int pivot = vec[low];
    int left = low + 1;
    int right = high;

    while (true) {
        // Move left pointer until we find an element greater than the pivot
        while (left <= right && vec[left] <= pivot) {
            ++left;
        }
        // Move right pointer until we find an element less than the pivot
        while (left <= right && vec[right] >= pivot) {
            --right;
        }
        if (left > right) {
            break;
        }
        // Swap the left and right elements
        std::swap(vec[left], vec[right]);
    }
    // Place the pivot in its correct position
    std::swap(vec[low], vec[right]);
    return right;
}

// Recursive quicksort function
void quickSortHelper(std::vector<int>& vec, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(vec, low, high);
        // Recursively sort elements on the left of the pivot
        quickSortHelper(vec, low, pivotIndex - 1);
        // Recursively sort elements on the right of the pivot
        quickSortHelper(vec, pivotIndex + 1, high);
    }
}
