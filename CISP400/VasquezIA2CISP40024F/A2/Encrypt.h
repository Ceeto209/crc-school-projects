// Name: Israel Vasquez
// Assignment#: A2 
// Purpose: create class for Encrypt . 
// Course: CISP 400 F24
// File Name: Encrypt.h

class Encrypt {
private:
    int digits[8]; // First 4 elements for original digits, next 4 for encrypted data
    int originalNumber; // To store the passed-in number
    void encryptData(); // Helper function to perform the encryption

public:
    // Constructor to accept an integer and initialize the object
    Encrypt(int number);

    // Function to display original data
    void displayOriginalData() const;

    // Function to store new data and encrypt it
    void storeData(int number);

    // Function to display encrypted data
    void displayEncryptedData() const;
};


