// Name: Israel Vasquez
// Assignment#: A3
// File Name: GradeBook.cpp
// Purpose: Member-function definitions for class GradeBook that
// Course: CISP 400 F24
#include <iostream>
#include <iomanip>
#include <string>
#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

// constructor initializes courseName with string supplied as argument;
// initializes counter data members to 0
GradeBook::GradeBook( string name )
{
   cout << "The Grade Book Constructor is called" << endl;
   setCourseName( name );
   initializeData(); // initialize grade arrays
   displayGradeReport();
   cout << "\n*****The end of Grade Book Constructor.*****" << endl << endl << endl;
} // end GradeBook constructor

// function to set the course name; limits name to 25 or fewer characters
void GradeBook::setCourseName( string name )
{
   if ( name.size() <= 30 ) // if name has 25 or fewer characters
      courseName = name; // store the course name in the object
   else // if name is longer than 25 characters
   { // set courseName to first 25 characters of parameter name
       courseName = name.substr(0, 30); // take only the first 30 characters
       cerr << "     Name: \"" << name << "\"\n     exceeds maximum length (30).\n"
           << "\n     Limiting courseName to first 30 characters.\n" << endl;
   } // end if...else
} // end function setCourseName

// function to retrieve the course name
string GradeBook::getCourseName() const
{
   return courseName;
} // end function getCourseName

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
   // this statement calls getCourseName to get the 
   // name of the course this GradeBook represents
   cout << "     Welcome to the grade book for\n     " << getCourseName() << "!\n" 
      << endl;
} // end function displayMessage

// Initialize data members ( reset counts and arrays )
void GradeBook::initializeData() {
    for (int i = 0; i < 6; ++i) {
        countGrades[i] = 0; // reset grade counts
    }
    for (int i = 0; i < 100; ++i) {
        letterGrades[i] = '\0'; // reset input storage
    }
}

// Input grades, store in letterGrades array, and validate input
void GradeBook::inputGrades() {
    char grade;
    int i = 0;

    cout << "     Enter the letter grades.\n"
        << "     Or Enter the EOF character to end input.\n"
        << "     (Use Ctl + D, or Ctl + Z)" << endl;
    
    while (i < 100) {
        //cout << ""; // Prompt for user input
        grade = cin.get(); // Get the next character (including whitespace/newlines)

        // Check for EOF to end input
        if (grade == EOF) {
            break;
        }

        // Handle newline (enter key) without incrementing i
        if (grade == '\n') {
            continue;
        }

        // Store the grade in letterGrades array
        letterGrades[i++] = grade;

        // Convert to uppercase for easier comparison
        switch (toupper(grade)) {
        case 'A':
            countGrades[0]++; // A grades
            break;
        case 'B':
            countGrades[1]++; // B grades
            break;
        case 'C':
            countGrades[2]++; // C grades
            break;
        case 'D':
            countGrades[3]++; // D grades
            break;
        case 'F':
            countGrades[4]++; // F grades
            break;
        default:
            countGrades[5]++; // Invalid input (error)
            cout << "     XXXX An incorrect letter grade entered.  XXXX" << endl << "     ";
            cout << "\"" << grade << "\" is not a proper letter grade.\n" << endl;
            break;
        }

        // Re-prompt the user after handling each input
        cout << "\n     Enter letter grades.\n"
            << "     -->     Or Enter the EOF character to end input.\n"
            << "     (Use Ctl + D, or Ctl + Z)" << endl;
    }
} // end function inputGrades

// Display all inputs (valid and invalid)
void GradeBook::displayInputs() const {
    cout << "\nThe data entered is listed at the following:\n";
    for (int i = 0; i < 100 && letterGrades[i] != '\0'; ++i) {
        cout << letterGrades[i] << "\t";
        if ((i + 1) % 4 == 0) { // display 4 per line
            cout << endl;
        }
    }
    cout << endl;
}

// Calculate GPA based on the valid grades
double GradeBook::calculateGrade() const {
    int totalGrades = countGrades[0] + countGrades[1] + countGrades[2] + countGrades[3] + countGrades[4];
    if (totalGrades == 0) return 0.0; // avoid division by zero

    double totalPoints = (countGrades[0] * 4.0) + (countGrades[1] * 3.0) + (countGrades[2] * 2.0) + (countGrades[3] * 1.0);
    return totalPoints / totalGrades; // return GPA
}

// display a report based on the grades entered by user
void GradeBook::displayGradeReport() const
{
   // output summary of results
    int totalStudents = countGrades[0] + countGrades[1] + countGrades[2] +
        countGrades[3] + countGrades[4];
    int totalInputs = totalStudents + countGrades[5]; // total including errors

    cout << "\nThe total number of data entered is " << totalInputs << endl;
    cout << "The total number of students receive grades is " << totalStudents << endl;

    cout << "\nNumber of students who received each letter grade:\n";
    cout << "A:\t" << countGrades[0] << endl;
    cout << "B:\t" << countGrades[1] << endl;
    cout << "C:\t" << countGrades[2] << endl;
    cout << "D:\t" << countGrades[3] << endl;
    cout << "F:\t" << countGrades[4] << endl;
    cout << "Error:\t" << countGrades[5] << endl;

    cout << fixed << setprecision(1);
    cout << "\nThe class average is: " << calculateGrade() << endl;
} // end function displayGradeReport

// Deconstructor to clean up memory
GradeBook::~GradeBook() {
    cout << "Destructor is called\n" << endl;
}