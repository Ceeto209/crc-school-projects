// Name: Israel Vasquez
// Assignment#: A5
// File Name: Permute.h
// Purpose: Header file for the Permute class which generates all permutations
//          of a string and stores them in a linked list
// Course: CISP 430 SP25

#ifndef PERMUTE_H
#define PERMUTE_H

#include <string>

class Node; // Forward declaration

class Permute {
private:
    Node* firstNode;        // Pointer to first node in the linked list
    Node* lastNode;         // Pointer to last node in the linked list
    int total;              // Total number of permutations
    std::string firstString;    // First input string
    std::string secondString;   // Second input string

    // Helper function for recursive permutation generation
    void permutationHelper(std::string prefix, std::string remaining);

public:
    // Constructor that takes two strings and generates permutations
    Permute(const std::string& first, const std::string& second);

    // Destructor to clean up linked list memory
    ~Permute();

    // Generates all permutations of firstString followed by secondString
    void permutation();

    // Prints all permutations in the required format
    void print() const;
};

#endif