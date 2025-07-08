// Name: Israel Vasquez
// Assignment#: A1
// GradeBook.cpp
// Purpose: GradeBook.cpp holds member-function definitions. This file contains
//          implementations of the member functions prototyped in GradeBook.h.
// Course: CISP 400 F24
// File Name: GradeBook.cpp

#include <iostream>
#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

// constructor initializes courseName with string supplied as argument
GradeBook::GradeBook( string name, string instructor )
   : courseName( name ), instructorName( instructor ) // member initializer to initialize courseName 
{                                                                      
   // empty body
} // end GradeBook constructor

// function to set the course name
void GradeBook::setCourseName( string name )
{
   courseName = name; // store the course name in the object
} // end function setCourseName

// function to get the course name
string GradeBook::getCourseName() const
{
   return courseName; // return object's courseName
} // end function getCourseName

void GradeBook::setInstructorName(string instructor)
{
    instructorName = instructor; // store the instructor name in the object
} // end function setInstructorName

// function to get the instructor name
string GradeBook::getInstructorName() const
{
    return instructorName; // return object's instructorName
} // end function getInstructorName

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
   // call getCourseName to get the courseName
    cout << "Welcome to the grade book for\n" << getCourseName()
        << "!" << endl << "This course is presented by: " << getInstructorName() << endl;
} // end function displayMessage

