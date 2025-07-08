// Name: Israel Vasquez
// Assignment#: A6
// File Name: Date.cpp
// Purpose: Date class member-function definitions
// Course: CISP 400 F24
#include "Date.h"

// Array of month names
const std::string Date::monthNames[12] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

// Helper function to validate the date
bool Date::isValidDate(int m, int d, int y) const {
    if (m < 1 || m > 12 || d < 1 || y < 0) return false;
    static const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (m == 2 && d == 29) return true; // Simplified leap year check
    return d <= daysInMonth[m - 1];
}

// Constructor with validation
Date::Date(int m, int d, int y) : month(m), day(d), year(y) {
    if (!isValidDate(month, day, year)) {
        // Default invalid dates to January 1, 2017
        month = 1;
        day = 1;
        year = 2017;
    }
}

// Overloaded equality operator
bool Date::operator==(const Date& other) const {
    return month == other.month && day == other.day && year == other.year;
}

// Overloaded stream insertion operator
std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << Date::monthNames[date.month - 1] << " " << date.day << ", " << date.year;
    return os;
}
