// Name: Israel Vasquez
// Assignment#: A7
// File Name: quicksort.h
// Purpose: Declares the quickSortHelper and partition functions
// Course: CISP 400 F24

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

// Function to perform quicksort on a vector
void quickSortHelper(std::vector<int>& vec, int low, int high);

// Function to partition the vector
int partition(std::vector<int>& vec, int low, int high);

#endif

