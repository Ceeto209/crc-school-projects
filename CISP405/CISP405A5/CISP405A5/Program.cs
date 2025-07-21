// Name: Israel Vasquez
// Assignment#: A5
// File Name: Program.cs
// Purpose: Main program for interacting with the Time1 class.
// Course: CISP 405 SU25

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static void Main()
    {
        Time1 time = new Time1();

        try
        {
            // Prompt for initial time input
            Console.WriteLine("Enter the time");
            Console.Write("Hours: ");
            int hour = int.Parse(Console.ReadLine());
            Console.Write("Minutes: ");
            int minute = int.Parse(Console.ReadLine());
            Console.Write("Seconds: ");
            int second = int.Parse(Console.ReadLine());

            time.SetTime(hour, minute, second); // Initialize time
        }
        catch (ArgumentOutOfRangeException)
        {
            Console.WriteLine("Invalid time entered. Please ensure hour is 0–23, minute and second are 0–59.");
            return;
        }

        bool running = true;

        while (running)
        {
            // Display time and menu
            Console.WriteLine("1. Add 1 Second");
            Console.WriteLine("2. Add 1 Minute");
            Console.WriteLine("3. Add 1 Hour");
            Console.WriteLine("4. Add Seconds");
            Console.WriteLine("5. Exit\n");

            Console.Write("Choice: ");
            string input = Console.ReadLine();

            switch (input)
            {
                case "1":
                    time.Tick(); // Add 1 second
                    PrintTime(time); // Display time
                    break;
                case "2":
                    time.IncrementMinute(); // Add 1 minute
                    PrintTime(time); // Display time
                    break;
                case "3":
                    time.IncrementHour(); // Add 1 hour
                    PrintTime(time); // Display time
                    break;
                case "4":
                    Console.Write("Enter seconds to tick: ");
                    if (int.TryParse(Console.ReadLine(), out int sec))
                    {
                        time.Tick(sec); // Add multiple seconds
                        PrintTime(time); // Display time
                    }
                    else
                    {
                        Console.WriteLine("Invalid number.\n");
                    }
                    break;
                case "5":
                    running = false; // Exit loop
                    break;
                default:
                    Console.WriteLine("Invalid choice.\n");
                    break;
            }
        }
    }

    /// Helper method to print time in required formats.
    static void PrintTime(Time1 time)
    {
        Console.WriteLine($"Hour: {time.Hour}  Minute: {time.Minute}  Second: {time.Second}");
        Console.WriteLine($"Universal time: {time.ToUniversalString()}   Standard time: {time.ToString()}");
    }
}
