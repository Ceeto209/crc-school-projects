// Name: Israel Vasquez
// Assignment#: A1
// File Name: stats.cpp
// Purpose: This source file contains the implementation of the statistician class, including the functionality for maintaining statistics, handling new input, and implementing operator overloads.
// Course: CISP 430 SP25

#include "stats.h"
#include <cassert>   // Includes assert function
#include <limits>    // For numeric_limits

namespace CISP430_A1 {

    // Constructor
    statistician::statistician() {
        reset(); // Using reset to initialize
    }

    // Modification Member Function
    void statistician::next(double r) {
        count++;             // Increment the count
        total += r;         // Add r to total
        values.push_back(r); // Store the value

        // Update tiniest and largest
        if (count == 1) { // First number
            tiniest = r;
            largest = r;
        }
        else {
            if (r < tiniest) {
                tiniest = r; // New smallest found
            }
            if (r > largest) {
                largest = r; // New largest found
            }
        }
    }

    // Reset Member Function
    void statistician::reset() {
        count = 0;
        total = 0.0;
        tiniest = std::numeric_limits<double>::max(); // Reset to max double
        largest = std::numeric_limits<double>::lowest(); // Reset to lowest double
        values.clear(); // Clear stored values
    }

    // Constant Member Function
    double statistician::mean() const {
        assert(count > 0); // Precondition: count must be greater than 0
        return total / count; // Calculate mean
    }

    // Constant Member Function
    double statistician::minimum() const {
        assert(count > 0); // Precondition: count must be greater than 0
        return tiniest; // Return the smallest number
    }

    // Constant Member Function
    double statistician::maximum() const {
        assert(count > 0); // Precondition: count must be greater than 0
        return largest; // Return the largest number
    }

    // Overloaded == Operator
    bool operator==(const statistician& s1, const statistician& s2) {
        if (s1.length() != s2.length()) return false; // Different lengths

        if (s1.length() == 0) return true; // Empty statistician are equal

        return (s1.sum() == s2.sum() &&
            s1.mean() == s2.mean() &&
            s1.minimum() == s2.minimum() &&
            s1.maximum() == s2.maximum());
    }

    // Overloaded + Operator
    statistician operator+(const statistician& s1, const statistician& s2) {
        statistician result;

        // Add all numbers from s1
        for (double value : s1.values) {
            result.next(value);
        }
        // Add all numbers from s2
        for (double value : s2.values) {
            result.next(value);
        }

        return result;
    }

    // Overloaded * Operator
    statistician operator*(double scale, const statistician& s) {
        statistician result;

        for (double value : s.values) {
            result.next(value * scale); // Scale each value and add it to result
        }

        return result;
    }

} // namespace CISP430_A1