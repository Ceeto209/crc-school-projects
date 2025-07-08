// Name: Israel Vasquez
// Assignment#: A5
// File Name: Node.h
// Purpose: Header file for the Node class which represents a node in a linked list
//          for storing string permutations
// Course: CISP 430 SP25

#ifndef NODE_H
#define NODE_H

#include <string>

class Node {
private:
    std::string data;   // Stores the permutation string
    Node* p;            // Pointer to the next node in the linked list

public:
    // Constructor to initialize a node with given data and next pointer
    Node(const std::string& data, Node* p = nullptr);

    friend class Permute; // Allow Permute to access private members
};

#endif
