// Name: Israel Vasquez
// Assignment#: A6
// File Name: CISP430V4A6.cpp
// Purpose: Test driver for the Table template class that demonstrates functionality
//          with various test cases. Tests include table creation, random insertion, 
//          removal, and assignment operations.
// Course: CISP 430 SP25

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "table2.h"

using namespace std;

/**
 * @brief Simple record structure for testing the hash table
 */
struct TestRecord {
    int key;
    TestRecord(int k = 0) : key(k) {}
    bool operator==(const TestRecord& other) const { return key == other.key; }
};

/**
 * @brief Prints table information in required format
 * @param table The table to print
 * @param name The name of the table for display
 */
void printTableInfo(const Table<TestRecord>& table, const string& name) {
    cout << "          Total records in the " << name << " is " << table.size() << endl;
    cout << "          Contains of the " << name << " display at below:" << endl;
    for (int i = 0; i < TABLE_SIZE; i++) {
        table.print(i); // Now calls print(int) for each index
    }
}

int main() {
    srand(time(0));

    // Step a: Instantiate two Table objects
    Table<TestRecord> TBObject1, TBObject2;

    // Step b: Display initial tables
    cout << "Instantiate two Table objects.\n" << endl;
    printTableInfo(TBObject1, "first Table object");
    cout << "----------------------------------------------------------------------------" << endl;
    printTableInfo(TBObject2, "second Table object");
    cout << "=============================================================================\n\n" << endl;

    // Step c: Insert random numbers
    cout << "**Using random number generator generates 70 numbers each for the objects.**\n" << endl;
    for (int i = 0; i < 70; i++) {
        TBObject1.insert(TestRecord(rand() % 201));
        TBObject2.insert(TestRecord(rand() % 201));
    }

    // Step d: Display after insertion
    printTableInfo(TBObject1, "first Table object");
    cout << "----------------------------------------------------------------------------" << endl;
    printTableInfo(TBObject2, "second Table object");
    cout << "=============================================================================\n\n" << endl;

    // Step e: Remove all from first object
    cout << "** Calling remove function removes all the contents in first object. **\n" << endl;
    bool found;
    TestRecord record;
    for (int key = 0; key <= 200; key++) {
        TBObject1.find(key, found, record);
        if (found) TBObject1.remove(key);
    }

    // Step f: Display after removal
    printTableInfo(TBObject1, "first Table object");
    cout << "----------------------------------------------------------------------------" << endl;
    printTableInfo(TBObject2, "second Table object");
    cout << "=============================================================================\n\n" << endl;

    // Step g: Assign second to first
    cout << "** Using TBObject1 = TBObject2 displays the assignment operator overloading. **\n" << endl;
    TBObject1 = TBObject2;

    // Step h: Display after assignment
    printTableInfo(TBObject1, "first Table object");
    cout << "----------------------------------------------------------------------------" << endl;
    printTableInfo(TBObject2, "second Table object");
    cout << "=============================================================================\n\n" << endl;

    cout << "Press any key to continue . . .";

    return 0;
}