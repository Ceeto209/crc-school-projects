// Name: Israel Vasquez
// Assignment#: A2
// File Name: AccountTest.cs
// Purpose: Demonstrates usage of Account class with validation on deposit and withdrawal.
// Course: CISP 405 SU25

using System;

class AccountTest
{
    static void Main()
    {
        Account account1 = new Account("Jane Green", 50.00m);
        Account account2 = new Account("John Blue", 0.00m);

        // display initial balance of each object
        Console.WriteLine("  $$$  Display information of Accounts  $$$");
        Console.WriteLine($"account1: {account1.Name} balance: {account1.Balance:C}");
        Console.WriteLine($"account2: {account2.Name} balance: {account2.Balance:C}");

        // Deposit to account1
        Console.Write("\nEnter deposit amount for account1: "); 
        decimal depositAmount = decimal.Parse(Console.ReadLine());
        Console.WriteLine($"adding {depositAmount:C} to account1 balance");
        account1.Deposit(depositAmount); // add to account1's balance

        // display balances
        DisplayBalances(account1, account2);

        // Deposit to account2
        Console.Write("\nEnter deposit amount for account2: ");
        depositAmount = decimal.Parse(Console.ReadLine());
        Console.WriteLine($"adding {depositAmount:C} to account2 balance");
        account2.Deposit(depositAmount); // add to account2's balance

        // display balances
        DisplayBalances(account1, account2);

        // Withdraw from account1
        Console.Write("\nEnter withdrawal amount for account1: "); // ask for withdraw of account1
        decimal debitAmount = decimal.Parse(Console.ReadLine()); // get withdraw for account1
        Console.WriteLine($"\nsubtracting {debitAmount:C} from account1 balance"); // show amount withdrew
        account1.Debit(debitAmount); // subtract from account1's balance
        
        // display balances
        DisplayBalances(account1, account2);

        // Withdraw from account2
        Console.Write("\nEnter withdrawal amount for account2: "); // ask for withdraw of account2
        debitAmount = decimal.Parse(Console.ReadLine()); // get withdraw for account2
        Console.WriteLine($"\nsubtracting {debitAmount:C} from account2 balance"); // show amount withdrew
        account2.Debit(debitAmount); // subtract from account2's balance

        // display balances
        DisplayBalances(account1, account2);

        // Ask for key to exit program
        Console.WriteLine("\nPress any key to exit.");
        Console.ReadKey();

    }
    
    static void DisplayBalances(Account a1, Account a2) // Method to display Account balances
    {
        Console.WriteLine("\n  $$$  Display information of Accounts  $$$");
        Console.WriteLine($"account1: {a1.Name} balance: {a1.Balance:C}");
        Console.WriteLine($"account2: {a2.Name} balance: {a2.Balance:C}");
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
 *************************************************************************/
