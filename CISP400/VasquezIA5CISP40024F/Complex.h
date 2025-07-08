// Name: Israel Vasquez
// Assignment#: A5
// File Name: Complex.h
// Purpose: Complex class definition.
// Course: CISP 400 F24

#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
   explicit Complex( double = 0.0, double = 0.0 ); // constructor
   Complex operator+( const Complex & ) const; // addition
   Complex operator-( const Complex & ) const; // subtraction
   Complex operator*( const Complex & ) const; // multiplication
   Complex operator/( const Complex & ) const; // division
   Complex& operator=( const Complex & ); // equals
   bool operator==( const Complex & ) const; // equals to
   bool operator!=( const Complex & ) const; // not equals to
   friend std::ostream &operator<<( std::ostream &, const Complex & );
   friend std::istream &operator>>(std::istream &, Complex & );
   void print() const; // output
private:
   double real; // real part
   double imaginary; // imaginary part
}; // end class Complex

#endif
