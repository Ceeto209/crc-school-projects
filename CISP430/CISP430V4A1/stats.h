// Name: Israel Vasquez
// Assignment#: A1
// File Name: stats.h
// Purpose: This header file declares the statistician class, including its member variables and function prototypes for operations like adding values and calculating statistics.
// Course: CISP 430 SP25

// CLASS PROVIDED: statistician
//   (a class to keep track of statistics on a sequence of real numbers)
//   This class is part of the namespace CISP430_A1.
//
// CONSTRUCTOR for the statistician class:
//   statistician( );
//     Postcondition: The object has been initialized, and is ready to accept
//     a sequence of numbers. Various statistics will be calculated about the
//     sequence.
//
// PUBLIC MODIFICATION member functions for the statistician class:
//   void next(double r)
//     The number r has been given to the statistician as the next number in
//     its sequence of numbers.
//   void reset( );
//     Postcondition: The statistician has been cleared, as if no numbers had
//     yet been given to it.
//   
// PUBLIC CONSTANT member functions for the statistician class:
//   int length( ) const
//     Postcondition: The return value is the length of the sequence that has
//     been given to the statistician (i.e., the number of times that the
//     next(r) function has been activated).
//   double sum( ) const
//     Postcondition: The return value is the sum of all the numbers in the
//     statistician's sequence.
//   double mean( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the arithmetic mean (i.e., the
//     average of all the numbers in the statistician's sequence).
//   double minimum( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the tiniest number in the
//     statistician's sequence.
//   double maximum( ) const
//     Precondition: length( ) > 0
//     Postcondition: The return value is the largest number in the
//     statistician's sequence.
//
// NON-MEMBER functions for the statistician class:
//   statistician operator +(const statistician& s1, const statistician& s2)
//     Postcondition: The statistician that is returned contains all the
//     numbers of the sequences of s1 and s2.
//   statistician operator *(double scale, const statistician& s)
//     Postcondition: The statistician that is returned contains the same
//     numbers that s does, but each number has been multiplied by the
//     scale number.
//   bool operator ==(const statistician& s1, const statistician& s2)
//     Postcondition: The return value is true if s1 and s2 have the zero
//     length. Also, if the length is greater than zero, then s1 and s2 must
//     have the same length, the same  mean, the same minimum, 
//     the same maximum, and the same sum.
//     
// VALUE SEMANTICS for the statistician class:
// Assignments and the copy constructor may be used with statistician objects.

#ifndef STATS_H     // Prevent duplicate definition
#define STATS_H
#include <iostream>
#include <vector>

namespace CISP430_A1
{
    class statistician
    {
    public:
        // CONSTRUCTOR
        statistician();
        // MODIFICATION MEMBER FUNCTIONS
        void next(double r);
        void reset();
        // CONSTANT MEMBER FUNCTIONS
        int length() const { return count; }
        double sum() const { return total; }
        double mean() const;
        double minimum() const;
        double maximum() const;
        // FRIEND FUNCTIONS
        friend statistician operator +
            (const statistician& s1, const statistician& s2);
        friend statistician operator *
            (double scale, const statistician& s);
    private:
        int count;       // How many numbers in the sequence
        double total;    // The sum of all the numbers in the sequence
        double tiniest;  // The smallest number in the sequence
        double largest;  // The largest number in the sequence
        std::vector<double> values; // Store all the values added
    };

    // NON-MEMBER functions for the statistician class
    bool operator ==(const statistician& s1, const statistician& s2);
}

#endif
