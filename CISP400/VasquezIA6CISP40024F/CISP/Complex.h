// Name: Israel Vasquez
// Assignment#: A6
// File Name: Complex.h
// Purpose: Complex class definition
// Course: CISP 400 F24
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <cmath>

class Complex {
private:
    double real, imaginary;

public:
    Complex(double r = 0.0, double i = 0.0);

    bool operator==(const Complex& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

#endif // COMPLEX_H
