// Name: Israel Vasquez
// Assignment#: A5
// File Name: Node.cpp
// Purpose: Implementation file for the Node class
// Course: CISP 430 SP25

#include "Node.h"

/**
 * Node constructor
 * @param data The string data to store in the node
 * @param p Pointer to the next node in the list (defaults to nullptr)
 */

Node::Node(const std::string& data, Node* p) : data(data), p(p) {}