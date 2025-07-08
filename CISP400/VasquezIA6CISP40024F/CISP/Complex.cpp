// Name: Israel Vasquez
// Assignment#: A6
// File Name: Complex.cpp
// Purpose: Complex class member-function definitions
// Course: CISP 400 F24
#include "Complex.h"

// Constructor
Complex::Complex(double r, double i) : real(r), imaginary(i) {}

// Overloaded equality operator
bool Complex::operator==(const Complex& other) const {
    return real == other.real && imaginary == other.imaginary;
}

// Overloaded stream insertion operator
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real << (c.imaginary >= 0 ? " + " : " - ") << std::abs(c.imaginary) << "i";
    return os;
}
