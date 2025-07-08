// Name: Israel Vasquez
// Assignment#: A4
// File Name: pqueue1.cpp
// Purpose: IMPLEMENTATION FILE FOR PriorityQueue CLASS
// This file implements the PriorityQueue class, which is a priority queue
// implemented using a linked list. Items are stored in the queue with an
// associated priority, and the item with the highest priority is always
// removed first.
// Course: CISP 430 SP25


#include "pqueue1.h" // Include the header file for the PriorityQueue class
#include <cassert>  // Provides assert for debugging

// Constructor
PriorityQueue::PriorityQueue() {
    head_ptr = nullptr; // Set the head pointer to null (empty list)
    many_nodes = 0; // Initialize the node count to 0
}

// Destructor
PriorityQueue::~PriorityQueue() {
    Node* cursor = head_ptr; // Start at the head of the list
    while (cursor != nullptr) {
        Node* next = cursor->link; // Save the next node
        delete cursor;             // Delete the current node
        cursor = next;             // Move to the next node
    }
}

// Copy Constructor
PriorityQueue::PriorityQueue(const PriorityQueue& source) {
    head_ptr = nullptr;  // Initialize the new list as empty
    many_nodes = 0;
    *this = source;  // Use the assignment operator to copy the source
}

// Assignment Operator
void PriorityQueue::operator=(const PriorityQueue& source) {
    if (this == &source) return;  // Handle self-assignment

    // Clear the current list to avoid memory leaks
    Node* cursor = head_ptr;
    while (cursor != nullptr) {
        Node* next = cursor->link;  // Save the next node
        delete cursor;              // Delete the current node
        cursor = next;              // Move to the next node
    }
    head_ptr = nullptr;  // Set the head pointer to null
    many_nodes = 0;      // Reset the node count

    // Copy the source list
    if (source.head_ptr != nullptr) {
        // Create the first node as a copy of the source's head node
        head_ptr = new Node{ source.head_ptr->data, source.head_ptr->priority, nullptr };
        many_nodes++;   // Increment the node count

        // Copy the rest of the nodes
        Node* source_cursor = source.head_ptr->link;  // Start at the second node in the source
        Node* this_cursor = head_ptr;                 // Start at the head of the new list
        while (source_cursor != nullptr) {
            // Create a new node as a copy of the current source node
            this_cursor->link = new Node{ source_cursor->data, source_cursor->priority, nullptr };
            many_nodes++;  // Increment the node count
            this_cursor = this_cursor->link;  // Move to the next node in the new list
            source_cursor = source_cursor->link;  // Move to the next node in the source list
        }
    }
}

void PriorityQueue::insert(const Item& entry, unsigned int priority) {
    // Create a new node with the given data and priority
    Node* new_node = new Node{ entry, priority, nullptr };

    // If the queue is empty or the new node has higher priority than the head
    if (head_ptr == nullptr || priority > head_ptr->priority) {
        new_node->link = head_ptr;  // Insert at the front
        head_ptr = new_node;        // Update the head pointer
    }
    else {
        // Traverse the list to find the correct position for the new node
        Node* cursor = head_ptr;
        while (cursor->link != nullptr && cursor->link->priority >= priority) {
            cursor = cursor->link;  // Move to the next node
        }
        // Insert the new node after the current node
        new_node->link = cursor->link;
        cursor->link = new_node;
    }
    many_nodes++;  // Increment the node count
}

PriorityQueue::Item PriorityQueue::get_front() {
    assert(!is_empty());  // Ensure the queue is not empty

    Node* front_node = head_ptr;  // Save the front node
    Item front_item = front_node->data;  // Save the data from the front node
    head_ptr = head_ptr->link;  // Move the head pointer to the next node
    delete front_node;  // Delete the old front node
    many_nodes--;  // Decrement the node count
    return front_item;  // Return the data from the front node
} 