// Name: Israel Vasquez
// Assignment#: A1
// File Name: Program.cs
// Purpose: Initialize the program
// Course: CISP 405 SU25

namespace CISP405A1
{
    internal static class Program
    {
        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            // To customize application configuration such as set high DPI settings or default font,
            // see https://aka.ms/applicationconfiguration.
            ApplicationConfiguration.Initialize();
            Application.Run(new Form1());
        }
    }
}