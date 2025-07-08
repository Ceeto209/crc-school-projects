// Name: Israel Vasquez
// Assignment#: A4
// File Name: Date.cpp
// Purpose: Date class member-function definitions
// Course: CISP 400 F24
#include <array>
#include <iostream>
#include <stdexcept>
#include "Date.h" // include Date class definition
using namespace std;

// constructor confirms proper value for month; calls
// utility function checkDay to confirm proper value for day
Date::Date( int mn, int dy, int yr, Time t ) : time(t)
{
   if ( mn > 0 && mn <= monthsPerYear ) // validate the month
      month = mn;
   else 
      throw invalid_argument( "month must be 1-12" );

   year = yr; // could validate yr
   day = checkDay( dy ); // validate the day

   // output Date object to show when its constructor is called
   cout << "Date object constructor for date ";
   print();                   
   cout << endl;
} // end Date constructor

// print Date object in form month/day/year
void Date::print() const
{
   cout << " " << month << '/' << day << '/' << year << "    ";
   time.printStandard(); // print time along with date
   cout << "    ";
   time.printUniversal();
   
} // end function print

// utility function to confirm proper day value based on 
// month and year; handles leap years, too
unsigned int Date::checkDay(int testDay) const
{
    static const array< int, monthsPerYear + 1 > daysPerMonth =
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // determine whether testDay is valid for specified month
    if (testDay > 0 && testDay <= daysPerMonth[month])
        return testDay;

    // February 29 check for leap year 
    if (month == 2 && testDay == 29 && (year % 400 == 0 ||
        (year % 4 == 0 && year % 100 != 0)))
        return testDay;

    throw invalid_argument("Invalid day for current month and year");

} // end function checkDay

// Increment time by one second and handle day change if necessary
void Date::tick()
{
    // Increment the time by one second
    // Check if seconds have rolled over to 0
    if (time.getSecond() + 1 == 60)
    {
        time.setSecond(0);
        if (time.getMinute() + 1 == 60)
        {
            time.setMinute(0);
            // Check if hours have rolled over to 0
            if (time.getHour() + 1 == 24)
            {
                time.setHour(0);
                increaseADay(); // Time reached 00:00:00, so increment the day
            }
            else
            {
                time.setHour(time.getHour() + 1);
            }
        }
        else
        {
            time.setMinute(time.getMinute() + 1);
        }
    }
    else
    {
        time.setSecond(time.getSecond() + 1);
    }
}


// Increment date by one day
void Date::increaseADay()
{
    day++; // Increment the day
    try
    {
        checkDay(day);
    }
    catch (invalid_argument e)
    {
        day = 1; // Reset to the first day of the next month
        month++; // Move to the next month
        if (month > monthsPerYear)
        {
            month = 1; // January
            year++;    // Increment the year
        }
    }
    // Check if the day exceeds the maximum for the current month
}




// output Date object to show when its destructor is called
Date::~Date()
{
    cout << "Date object destructor is called" << endl;
    print();
    cout << endl;
    
} // end ~Date destructor