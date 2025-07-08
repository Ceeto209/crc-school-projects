// Name: Israel Vasquez
// Assignment#: A5
// File Name: Driver.cpp
// Purpose: Test driver for the Permute class that demonstrates functionality
//          with various test cases as specified in the assignment
// Course: CISP 430 SP25

#include "Permute.h"
#include <iostream>

int main() {
    const int SIZE = 8;
    Permute* permuteArray[SIZE];

    // Initialize the array with the specified test cases
    permuteArray[0] = new Permute("", "");
    permuteArray[1] = new Permute("", "CATMAN");
    permuteArray[2] = new Permute("C", "ATMAN");
    permuteArray[3] = new Permute("CA", "TMAN");
    permuteArray[4] = new Permute("CAT", "MAN");
    permuteArray[5] = new Permute("CATM", "AN");
    permuteArray[6] = new Permute("CATMA", "N");
    permuteArray[7] = new Permute("CATMAN", "");

    // Print results for each test case
    for (int i = 0; i < SIZE; i++) {
        permuteArray[i]->print();
    }

    // Clean up
    for (int i = 0; i < SIZE; i++) {
        delete permuteArray[i];
    }

    std::cout << "Press any key to continue . . .";
    return 0;
}