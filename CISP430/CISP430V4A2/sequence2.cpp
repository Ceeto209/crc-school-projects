// Name: Israel Vasquez
// Assignment#: A2
// File Name: sequence2.cpp
// Purpose: This implementation file defines the member functions of the sequence2 class, 
// including dynamic memory allocation, resizing, and sequence operations. It ensures the sequence can grow 
// dynamically and handles edge cases like removing the last item.
// Course: CISP 430 SP25

#include "sequence2.h"  // Include the header file
#include <stdexcept>    // For std::runtime_error


namespace CISP430_A2 {

    // CONSTRUCTOR
    sequence::sequence(size_type initial_capacity) {
        capacity = initial_capacity;
        data = new value_type[capacity];
        used = 0;
        current_index = 0;
    }

    // COPY CONSTRUCTOR
    sequence::sequence(const sequence& other) {
        capacity = other.capacity;
        used = other.used;
        current_index = other.current_index;
        data = new value_type[capacity];
        for (size_type i = 0; i < used; ++i) {
            data[i] = other.data[i];
        }
    }

    // DESTRUCTOR
    sequence::~sequence() {
        delete[] data;
    }

    // ASSIGNMENT OPERATOR
    void sequence::operator=(const sequence& other) {
        if (this == &other) return; // Handle self-assignment

        delete[] data; // Free existing resources

        capacity = other.capacity;
        used = other.used;
        current_index = other.current_index;
        data = new value_type[capacity];
        for (size_type i = 0; i < used; ++i) {
            data[i] = other.data[i];
        }
    }

    // RESIZE FUNCTION
    void sequence::resize(size_type new_capacity) {
        if (new_capacity < used) return; // Do not resize if new_capacity is less than used

        value_type* new_data = new value_type[new_capacity];
        for (size_type i = 0; i < used; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

    // INSERT FUNCTION
    void sequence::insert(const value_type& entry) {
        if (used == capacity) {
            resize(capacity + capacity / 10 + 1); // Increase capacity by 10%
        }

        if (!is_item()) {
            current_index = 0;
        }

        for (size_type i = used; i > current_index; --i) {
            data[i] = data[i - 1];
        }
        data[current_index] = entry;
        ++used;
    }

    // ATTACH FUNCTION
    void sequence::attach(const value_type& entry) {
        if (used == capacity) {
            resize(capacity + capacity / 10 + 1); // Increase capacity by 10%
        }

        if (!is_item()) {
            current_index = used;
        }
        else {
            ++current_index;
        }

        for (size_type i = used; i > current_index; --i) {
            data[i] = data[i - 1];
        }
        data[current_index] = entry;
        ++used;
    }

    // REMOVE CURRENT FUNCTION
    void sequence::remove_current() {
        if (!is_item()) return; // No current item to remove

        // Shift all elements after the current item to the left
        for (size_type i = current_index; i < used - 1; ++i) {
            data[i] = data[i + 1];
        }
        --used; // Decrease the number of items in the sequence

        // Adjust the current_index if necessary
        if (used == 0) {
            // If the sequence is now empty, reset current_index to indicate no valid item
            current_index = 0;
        }
        else if (current_index >= used) {
            // If the current item was the last one, set current_index to indicate no valid item
            current_index = used; 
        }
    }

    // START FUNCTION
    void sequence::start() {
        current_index = 0;
    }

    // ADVANCE FUNCTION
    void sequence::advance() {
        if (is_item()) {
            ++current_index;
        }
    }

    // SIZE FUNCTION
    sequence::size_type sequence::size() const {
        return used;
    }

    // IS_ITEM FUNCTION
    bool sequence::is_item() const {
        return current_index < used;
    }

    // CURRENT FUNCTION
    sequence::value_type sequence::current() const {
        if (!is_item()) {
            throw std::runtime_error("No current item");
        }
        return data[current_index];
    }
}