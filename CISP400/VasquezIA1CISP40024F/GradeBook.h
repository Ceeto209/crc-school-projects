// Name: Israel Vasquez
// Assignment#: A1
// Purpose: GradeBook class definition. This file presents GradeBook's public 
//          interface without revealing the implementations of GradeBook's member
//          functions, which are defined in GradeBook.cpp.
// Course: CISP 400 F24
// File Name: GradeBook.h

#include <string> // class GradeBook uses C++ standard string class

// GradeBook class definition
class GradeBook
{
public:
   explicit GradeBook( std::string, std::string instructor ); // constructor initialize courseName
   void setCourseName( std::string ); // sets the course name
   std::string getCourseName() const; // gets the course name
   void displayMessage() const; // displays a welcome message

   // set instructor name
   void setInstructorName(std::string);
   // function to get the instructor name
   std::string getInstructorName() const;
   
private:
   std::string courseName; // course name for this GradeBook
   std::string instructorName; // instructor name for this GradeBook
}; // end class GradeBook  


