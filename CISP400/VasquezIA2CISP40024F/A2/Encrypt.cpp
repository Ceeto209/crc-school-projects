// Name: Israel Vasquez
// Assignment#: A2 
// Purpose: Create functions for Encrypt class in headerfile Encrypt.h . 
// Course: CISP 400 F24
// File Name: Encrypt.cpp

#include "Encrypt.h"
#include <iostream>

using namespace std;

// Private helper function to perform the encryption
void Encrypt::encryptData() {
    // Encrypt each digit using (digit + 7) % 10
    for (int i = 0; i < 4; ++i) {
        digits[i + 4] = (digits[i] + 7) % 10;
    }

    // Swap the first digit with the third, and the second with the fourth
    std::swap(digits[4], digits[6]);
    std::swap(digits[5], digits[7]);
}

// Constructor: initializes the object with the passed number
Encrypt::Encrypt(int number) {
    cout << "\n** The default constructor is called\n";
    cout << "   and the passed in number is " << number << ".**\n\n";

    if (number <= 0) {
        cout << " XXX The inputed number is less than or equal to 0.\n";
        cout << "     The number is reset to 9436. XXX\n\n";
        number = 9436;
    }

    // Extract the last four digits of the number
    for (int i = 3; i >= 0; --i) {
        digits[i] = number % 10;
        number /= 10;
    }

    encryptData(); // Encrypt the extracted digits

    // Display original and encrypted data
    displayOriginalData();
    displayEncryptedData();
}

// Function to display the original data
void Encrypt::displayOriginalData() const {
    cout << "     The original data is  ";
    for (int i = 0; i < 4; ++i) {
        cout << digits[i] << " ";
    }
    cout << endl;
}

// Function to store new data and encrypt it
void Encrypt::storeData(int number) {

    if (number <= 0) {
        number = 9436; // Set to default value if input is less than or equal to 0
    }

    // Extract the last four digits
    for (int i = 3; i >= 0; --i) {
        digits[i] = number % 10;
        number /= 10;
    }

    encryptData(); // Encrypt the new data


}

// Function to display the encrypted data
void Encrypt::displayEncryptedData() const {
    cout << "     The encrypted data is  ";
    for (int i = 4; i < 8; ++i) {
        cout << digits[i] << " ";
    }
    cout << "." << endl;
}
