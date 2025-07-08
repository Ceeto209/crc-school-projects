// Name: Israel Vasquez
// Assignment#: A6
// File Name: Date.h
// Purpose: Date class definition
// Course: CISP 400 F24
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class Date {
private:
    int month, day, year;
    static const std::string monthNames[12];

    bool isValidDate(int m, int d, int y) const;

public:
    Date(int m = 1, int d = 1, int y = 2000);

    bool operator==(const Date& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

#endif // DATE_H
