// Name: Israel Vasquez
// Assignment#: A5
// File Name: Permute.cpp
// Purpose: Implementation file for the Permute class that generates and manages
//          string permutations in a linked list
// Course: CISP 430 SP25

#include "Permute.h"
#include "Node.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>


/**
 * Constructor that initializes the Permute object and generates permutations
 * @param first The first string to permute
 * @param second The second string to append after each permutation
 */
Permute::Permute(const std::string& first, const std::string& second)
    : firstNode(nullptr), lastNode(nullptr), total(0),
    firstString(first), secondString(second) {
    permutation();
}



//Destructor that cleans up all nodes in the linked list
Permute::~Permute() {
    Node* current = firstNode;
    while (current) {
        Node* next = current->p;
        delete current;
        current = next;
    }
}


/**
 * Recursive helper function to generate all permutations
 * @param remaining The remaining characters to permute
 * @param prefix The current prefix for the permutation being built
 */
void Permute::permutationHelper(std::string remaining, std::string prefix) {
    // Base case: no more characters to permute
    if (remaining.length() == 0) {
        // Create the permutation by combining with secondString
        std::string perm = prefix + secondString;

        // Create new node for the linked list
        Node* newNode = new Node(perm);

        if (!firstNode) {
            firstNode = lastNode = newNode;
        }
        else {
            lastNode->p = newNode;
            lastNode = newNode;
        }
        total++;
        return;
    }

    // Recursive case: generate permutations for each remaining character
    for (size_t i = 0; i < remaining.length(); i++) {
        std::string newPrefix = prefix + remaining[i];
        std::string newRemaining = remaining.substr(0, i) + remaining.substr(i + 1);
        permutationHelper(newRemaining, newPrefix);
    }
}


/**
 * Generates all permutations of firstString followed by secondString
 * Handles special case when both strings are empty
 */
void Permute::permutation() {
    if (firstString.empty() && secondString.empty()) {
        std::cout << "String 1 for this object is:\n";
        std::cout << "String 2 for this object is:\n";
        std::cout << "There is no permutation.\n\n";
        return;
    }
    permutationHelper(firstString, "");
}


/**
 * Prints all permutations in the required format
 * Sorts permutations before displaying to match example output
 */
void Permute::print() const {
    // Skip printing if both strings are empty (already handled)
    if (firstString.empty() && secondString.empty()) {
        return;
    }

    // Print header information
    std::cout << "String 1 for this object is: " << firstString << "\n";
    std::cout << "String 2 for this object is: " << secondString << "\n";

    // Handle case with no permutations
    if (total == 0) {
        std::cout << "There is no permutation.\n\n";
        return;
    }

    // Print permutation count
    std::cout << "The total possible permutation is " << total << "\n";

    // Use appropriate label (singular/plural)
    if (total == 1) {
        std::cout << "That is:\n";
    }
    else {
        std::cout << "They are:\n";
    }

    // Collect all permutations in a vector for sorting
    std::vector<std::string> permutations;
    Node* current = firstNode;
    while (current) {
        permutations.push_back(current->data);
        current = current->p;
    }

    // Sort the permutations to match the example order
    std::sort(permutations.begin(), permutations.end());

    // Print the sorted permutations
    int count = 0;
    int perRow = (total < 100) ? 4 : 9;

    for (const auto& perm : permutations) {
        std::cout << perm << "  ";
        count++;
        if (count % perRow == 0) {
            std::cout << "\n";
        }
    }

    // Add final newline if needed
    if (count % perRow != 0) {
        std::cout << "\n";
    }
    std::cout << "\n";
}