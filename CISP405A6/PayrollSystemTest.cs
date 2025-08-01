// Name: Israel Vasquez
// Assignment#: A6
// File Name: PayrollSystemTest.cs
// Purpose: Employee Payroll app
// Course: CISP 405 SU25

// Fig. 12.9: PayrollSystemTest.cs
// Employee hierarchy test app.
using System;
using System.Collections.Generic;

public class PayrollSystemTest
{
    public static void Main(string[] args)
    {
        // create derived class objects with birthdays
        SalariedEmployee salariedEmployee1 = new SalariedEmployee(
               "John", "Smith", "111-11-1111", 6, 15, 1944, 800M);
        HourlyEmployee hourlyEmployee1 = new HourlyEmployee(
               "Karen", "Price", "222-22-2222", 12, 29, 1960, 16.75M, 40M);
        CommissionEmployee commissionEmployee1 =
               new CommissionEmployee("Sue", "Jones", "333-33-3333",
               9, 8, 1954, 10000M, .06M);
        BasePlusCommissionEmployee basePlusCommissionEmployee1 =
               new BasePlusCommissionEmployee("Bob", "Lewis", "444-44-4444",
               3, 2, 1965, 5000M, .04M, 300M);

        SalariedEmployee salariedEmployee2 = new SalariedEmployee(
               "Afatarli", "Valeri", "511-11-1111", 1, 5, 1915, 600M);
        HourlyEmployee hourlyEmployee2 = new HourlyEmployee(
               "Henry", "Buris", "622-22-2222", 2, 9, 1970, 14.75M, 36M);
        CommissionEmployee commissionEmployee2 =
               new CommissionEmployee("Anthony", "Doss", "733-33-3333",
               4, 18, 1944, 10045M, .07M);
        BasePlusCommissionEmployee basePlusCommissionEmployee2 =
               new BasePlusCommissionEmployee("Bob", "Lewis", "844-44-4444",
               5, 1, 1960, 4300M, .05M, 290M);

        SalariedEmployee salariedEmployee3 = new SalariedEmployee(
               "Linda", "Ha", "911-11-1111", 7, 25, 1968, 400M);
        HourlyEmployee hourlyEmployee3 = new HourlyEmployee(
               "Brian", "Louie", "122-22-2222", 8, 6, 1966, 18.85M, 60M);
        CommissionEmployee commissionEmployee3 =
               new CommissionEmployee("Leon", "Powell", "233-33-3333",
               10, 22, 1959, 10100M, .07M);
        BasePlusCommissionEmployee basePlusCommissionEmployee3 =
               new BasePlusCommissionEmployee("David", "Tong", "344-44-4444",
               11, 8, 1970, 5080M, .08M, 400M);

        // Display all employees
        Console.WriteLine("Employees processed individually:\n");

        Console.WriteLine($"{salariedEmployee1}\nearned: {salariedEmployee1.Earnings():C}\n");
        Console.WriteLine($"{hourlyEmployee1}\nearned: {hourlyEmployee1.Earnings():C}\n");
        Console.WriteLine($"{commissionEmployee1}\nearned: {commissionEmployee1.Earnings():C}\n");
        Console.WriteLine($"{basePlusCommissionEmployee1}\nearned: {basePlusCommissionEmployee1.Earnings():C}\n");

        Console.WriteLine($"{salariedEmployee2}\nearned: {salariedEmployee2.Earnings():C}\n");
        Console.WriteLine($"{hourlyEmployee2}\nearned: {hourlyEmployee2.Earnings():C}\n");
        Console.WriteLine($"{commissionEmployee2}\nearned: {commissionEmployee2.Earnings():C}\n");
        Console.WriteLine($"{basePlusCommissionEmployee2}\nearned: {basePlusCommissionEmployee2.Earnings():C}\n");

        Console.WriteLine($"{salariedEmployee3}\nearned: {salariedEmployee3.Earnings():C}\n");
        Console.WriteLine($"{hourlyEmployee3}\nearned: {hourlyEmployee3.Earnings():C}\n");
        Console.WriteLine($"{commissionEmployee3}\nearned: {commissionEmployee3.Earnings():C}\n");
        Console.WriteLine($"{basePlusCommissionEmployee3}\nearned: {basePlusCommissionEmployee3.Earnings():C}\n");

        // create twelve-element Employee array
        Employee[] employees = new Employee[12]
        {
            salariedEmployee1, hourlyEmployee1, commissionEmployee1, basePlusCommissionEmployee1,
            salariedEmployee2, hourlyEmployee2, commissionEmployee2, basePlusCommissionEmployee2,
            salariedEmployee3, hourlyEmployee3, commissionEmployee3, basePlusCommissionEmployee3
        };

        int currentMonth;

        // get and validate current month
        do
        {
            Console.Write("Enter the current month (1 - 12): ");
            currentMonth = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine();
        } while (currentMonth < 1 || currentMonth > 12);

        Console.WriteLine("Employees processed polymorphically:\n");

        // process each element in array employees
        foreach (var currentEmployee in employees)
        {
            Console.WriteLine(currentEmployee); // invokes ToString

            // determine whether element is a BasePlusCommissionEmployee
            if (currentEmployee is BasePlusCommissionEmployee)
            {
                var employee = (BasePlusCommissionEmployee)currentEmployee;
                employee.BaseSalary *= 1.10M;
                Console.WriteLine($"new base salary with 10% increase is: {employee.BaseSalary:C}");
            }

            // add birthday bonus if applicable
            decimal totalPay = currentEmployee.Earnings();
            if (currentMonth == currentEmployee.BirthDate.Month)
            {
                totalPay += 100M;
                Console.WriteLine($"earned {totalPay:C} plus $100.00 birthday bonus\n");
            } else
              {
                Console.WriteLine($"earned {totalPay:C}\n");
              }
        }

        // get type name of each object in employees array
        for (int j = 0; j < employees.Length; j++)
        Console.WriteLine($"Employee {j} is a {employees[j].GetType()}");

        // Pause so the window stays open
        Console.WriteLine("\nPress any key to exit...");
        Console.ReadKey();
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
