// Name: Israel Vasquez
// Assignment#: A7
// File Name: CISP400V10A7.cpp
// Purpose: Generates 10 random vectors
// Course: CISP 400 F24

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "quicksort.h"

void printVector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << "  ";
    }
    std::cout << std::endl;
}

int main() {
    std::srand(static_cast<unsigned>(std::time(0))); // Seed the random number generator

    for (int i = 0; i < 10; ++i) {
        // Generate a random vector size between 1 and 20
        int size = std::rand() % 20 + 1;
        std::vector<int> vec(size);

        // Populate the vector with random numbers between 0 and 100
        for (int& num : vec) {
            num = std::rand() % 101;
        }

        // Display the initial vector
        std::cout << "The " << i + 1 << "th set of data(" << size << "):\n";
        std::cout << "  Initial vector values are:\n  ";
        printVector(vec);

        // Perform quicksort
        quickSortHelper(vec, 0, vec.size() - 1);

        // Display the sorted vector
        std::cout << "  The sorted vector values are:\n  ";
        printVector(vec);
        std::cout << std::endl;
    }

    return 0;
}
