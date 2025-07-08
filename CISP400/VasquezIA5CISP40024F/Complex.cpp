// Name: Israel Vasquez
// Assignment#: A5
// File Name: Complex.cpp
// Purpose: Complex class member-function definitions
// Course: CISP 400 F24

#include <iostream>
#include "Complex.h" // Complex class definition
#include <stdexcept>
using namespace std;

// Constructor
Complex::Complex( double realPart, double imaginaryPart ) 
   : real( realPart ),
   imaginary( imaginaryPart ) 
{ 
   // empty body
} // end Complex constructor

// addition operator
Complex Complex::operator+( const Complex &operand2 ) const
{
   return Complex( real + operand2.real, 
      imaginary + operand2.imaginary );
} // end function operator+

// subtraction operator
Complex Complex::operator-( const Complex &operand2 ) const
{
   return Complex( real - operand2.real, 
      imaginary - operand2.imaginary );
} // end function operator-

// Multiplication
Complex Complex::operator*( const Complex &operand2 ) const {
    return Complex(real * operand2.real - imaginary * operand2.imaginary,
        real * operand2.imaginary + imaginary * operand2.real);
}

// Division
Complex Complex::operator/( const Complex &operand2 ) const {
    double denominator = operand2.real * operand2.real + operand2.imaginary * operand2.imaginary;
    if (denominator == 0) {
        return Complex(1e10, 1e10); // should we throw an error instead?
    }
    return Complex((real * operand2.real + imaginary * operand2.imaginary) / denominator,
        (imaginary * operand2.real - real * operand2.imaginary) / denominator);
}

// Assignment
Complex& Complex::operator=(  const Complex &operand2 ) {
    if (this != &operand2) { // prevent self-assignment
        real = operand2.real;
        imaginary = operand2.imaginary;
    }
    return *this;
}

// Equality
bool Complex::operator==( const Complex &operand2 ) const {
    return (real == operand2.real && imaginary == operand2.imaginary);
}

// Inequality
bool Complex::operator!=( const Complex &operand2) const {
    return !(*this == operand2);
}

// Overload << for output
std::ostream &operator<<( std::ostream &output, const Complex &c ) {
    if (c.real == 1e10 && c.imaginary == 1e10)
    {
        output << "infinite";
    }
    else
    {
        output << '(' << c.real << ", " << c.imaginary << ')';
    }
    return output;
}

// Overload >> for input
std::istream &operator>>( std::istream &input, Complex &c ) {
    char ch;
    input >> ch; //read '('
    input >> c.real; // read real part
    input >> ch; // read ','
    input >> c.imaginary; // read imaginary part
    input >> ch; // read ')'
    return input;
}

// display a Complex object in the form: (a, b)
void Complex::print() const
{ 
   cout << '(' << real << ", " << imaginary << ')';
} // end function print

