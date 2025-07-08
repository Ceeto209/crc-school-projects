// Name: Israel Vasquez
// Assignment#: A6
// File Name: CISP400V10A6.cpp
// Purpose: Main function to use Complex.cpp, Complex.h, Date.h and Date.ccp to output equalities between the stacks.
// Course: CISP 400 F24
#include <iostream>
#include <string>
#include "Date.h"
#include "Complex.h"

template <typename T>
bool isEqualTo(const T& a, const T& b) {
    return a == b;
}

template <typename T>
void testEquality(const std::string& testGroupName, const T& val1, const T& val2, const std::string& typeName) {
    std::cout << typeName << ": " << val1 << " and " << val2
        << (isEqualTo(val1, val2) ? " are equal\n" : " are \"NOT\" equal\n");
}

int main() {
    std::cout << "*** Integers Tests ***\n";
    testEquality("Integer", 1, 1, "Integers");
    testEquality("Integer", 2, 4, "Integers");
    testEquality("Integer", -1, 1, "Integers");
    testEquality("Integer", -1, -1, "Integers");

    std::cout << "\n*** Chars Tests ***\n";
    testEquality("Char", 'a', 'a', "Characters");
    testEquality("Char", 'a', 'c', "Characters");
    testEquality("Char", 'c', 'a', "Characters");
    testEquality("Char", 'c', 'c', "Characters");

    std::cout << "\n*** Double Tests ***\n";
    testEquality("Double", 2.2, 2.2, "Double numbers");
    testEquality("Double", 2.2, 2.3, "Double numbers");
    testEquality("Double", -2.2, 2.2, "Double numbers");
    testEquality("Double", -2.2, -2.2, "Double numbers");

    std::cout << "\n*** Complex Tests ***\n";
    testEquality("Complex", Complex(10, 5), Complex(10, 5), "Class objects");
    testEquality("Complex", Complex(10, 5), Complex(10, 54), "Class objects");
    testEquality("Complex", Complex(10, -5), Complex(10, 5), "Class objects");
    testEquality("Complex", Complex(-10, -5), Complex(-10, -5), "Class objects");

    std::cout << "\n*** String Tests ***\n";
    testEquality("String", std::string("abcdefg"), std::string("abcdefg"), "String objects");
    testEquality("String", std::string("abcdefg"), std::string("abcdefh"), "String objects");
    testEquality("String", std::string("-abcdefg"), std::string("abcdefg"), "String objects");
    testEquality("String", std::string("-abcdefg"), std::string("-abcdefg"), "String objects");

    std::cout << "\n*** Date Tests ***\n";
    testEquality("Date", Date(2, 31, 2017), Date(2, 31, 2017), "Date objects");
    testEquality("Date", Date(2, 13, 2017), Date(2, 14, 2017), "Date objects");
    testEquality("Date", Date(-2, 13, 2017), Date(2, 13, 2017), "Date objects");
    testEquality("Date", Date(-2, 13, 2017), Date(-2, 13, 2017), "Date objects");

    return 0;
}
