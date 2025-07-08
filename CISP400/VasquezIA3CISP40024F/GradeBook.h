// Name: Israel Vasquez
// Assignment#: A3
// File Name: GradeBook.h
// Purpose: GradeBook class definition that counts letter grades.
//          Member functions are defined in GradeBook.cpp
// Course: CISP 400 F24
#include <string> // program uses C++ standard string class

// GradeBook class definition
class GradeBook
{
public:
   explicit GradeBook( std::string ); // initialize course name
   void setCourseName( std::string ); // set the course name
   std::string getCourseName() const; // retrieve the course name
   void displayMessage() const; // display a welcome message
   void inputGrades(); // input arbitrary number of grades from user
   void displayGradeReport() const;  // display report based on user input
   void displayInputs() const; // display all inputs (valid or invalid)
   double calculateGrade() const; // calculate GPA
   void initializeData(); // initialize arrays
   ~GradeBook(); // deconstructor to clean data
private:
   std::string courseName; // course name for this GradeBook
   char letterGrades[100]; // array to store all inputs
   int countGrades[6]; // array to store counts of A, B, C, D, F, and invalid
}; // end class GradeBook  