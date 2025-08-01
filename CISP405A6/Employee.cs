// Name: Israel Vasquez
// Assignment#: A6
// File Name: Employee.cs
// Purpose: Employee abstract base class with BirthDate included for payroll system.
// Course: CISP 405 SU25

// Fig. 12.4: Employee.cs
// Employee abstract base class.
public abstract class Employee
{
    public string FirstName { get; }
    public string LastName { get; }
    public string SocialSecurityNumber { get; }
    public Date BirthDate { get; } // Employee birthdate

   // Constructor
    public Employee(string firstName, string lastName, string socialSecurityNumber, int month, int day, int year)
    {
        FirstName = firstName;
        LastName = lastName;
        SocialSecurityNumber = socialSecurityNumber;
        BirthDate = new Date(month, day, year);
    }

    // Abstract method overriden by subclasses/derived classes
    public abstract decimal Earnings();

    // return string representation of Employee object, using properties
    public override string ToString()
    {
        return string.Format("{0} {1}\nSocial Security Number: {2}\nBirth Date: {3}", FirstName, LastName, SocialSecurityNumber, BirthDate);
    }
 
}


/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
