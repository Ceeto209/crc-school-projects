// Name: Israel Vasquez
// Assignment#: A6
// File Name: table2.h
// Purpose: Header file for the Table template class implementing a chained hash table.
//          Defines the interface for hash table operations including insert, remove,
//          and search functionality.
// Course: CISP 430 SP25

#ifndef TABLE2_H
#define TABLE2_H

#include "link2.h"

const size_t TABLE_SIZE = 10;   // Size of the hash table array


/**
 * @brief Template class for a chained hash table
 * @tparam RecordType The type of records stored in the table, must contain an integer 'key' member
 */
template <class RecordType>
class Table {
public:
    // Constructors and destructor
    Table();
    ~Table();
    Table(const Table& source);

    // Operators
    void operator=(const Table& source);

    // Modification member functions
    void insert(const RecordType& entry);
    void remove(int key);
    void print(int index) const;

    // Constant member functions
    bool is_present(const RecordType& target) const;
    void find(int key, bool& found, RecordType& result) const;
    size_t size() const { return total_records; }

private:
    Node<RecordType>* data[TABLE_SIZE]; // Array of linked list head pointers
    size_t total_records;               // Count of records in the table

    // Helper functions
    size_t hash_func(int key) const;
    void clear();
    void copy(const Table& source);
};

#include "table2.template"
#endif