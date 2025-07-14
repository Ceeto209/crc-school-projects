// Name: Israel Vasquez
// Assignment#: A4
// File Name: SalesCommissionApp.cs
// Purpose: Implements a Sales person commission class that analizes their weekly commission depending on sales.
// Course: CISP 405 SU25

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CISP405A4
{
    internal class SalesCommissionApp
    {
        static void Main()
        {
            // Array to hold the number of salespeople in each salary range
            int[] salaryRanges = new int[9];

            // Promt user for input
            Console.Write("Enter sales amount (negative to end): ");
            string input = Console.ReadLine();

            while (int.TryParse(input, out int sales) && sales >= 0)
            {
                // Calculate weekly salary: base $200 + 9% commision on sales
                int salary = 200 + (int)(0.09 * sales); // Truncate to int

                // Determine the salary range index
                int index;

                if (salary >= 1000)
                {
                    index = 8; // $1000 and over
                }
                else
                {
                    index = (salary - 200) / 100; // Each range covers $100

                    if (index < 0) index = 0; // Clamp index just in case
                }

                // Increment the count for the determined salary range
                salaryRanges[index]++;

                // Prompt again
                Console.Write("Enter sales amount (negative to end): ");
                input = Console.ReadLine();
            }

            // Display header
            Console.WriteLine("{0,-15} {1}", "Range", "Number");

            // Display salary ranges from $200-999
            for (int i = 0; i < 8; i++) 
            {
                int lowerBound = 200 + i * 100;
                int upperBound = lowerBound + 99;
                string rangeLabel = $"${lowerBound}-${upperBound}";
                Console.WriteLine("{0,-15} {1}", rangeLabel, salaryRanges[i]);
            }

            // Display $1000 and over
            Console.WriteLine("{0,-15} {1}", "$1000 and over", salaryRanges[8]);

            // Ask for key to exit program
            Console.WriteLine("\nPress any key to exit.");
            Console.ReadKey();
        }
    }
}
