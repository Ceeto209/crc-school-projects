// Name: Israel Vasquez
// Assignment#: A4
// File Name: Date.h
// Purpose: Date class definition; Member functions defined in Date.cpp
// Course: CISP 400 F24
#ifndef DATE_H
#define DATE_H

#include "Time.h" // include Time.h

class Date 
{
public:
   static const unsigned int monthsPerYear = 12; // months in a year
   explicit Date( int = 1, int = 1, int = 1900, Time = Time() ); // default constructor
   void print() const; // print date in month/day/year format
   void tick(); // increment time by one second
   void increaseADay(); // increment date by one day
   ~Date(); // provided to confirm destruction order
private:
   unsigned int month; // 1-12 (January-December)
   unsigned int day; // 1-31 based on month
   unsigned int year; // any year
   Time time; // composition: Date has a Time object

   // utility function to check if day is proper for month and year
   unsigned int checkDay( int ) const; // check if day is valid
}; // end class Date

#endif
