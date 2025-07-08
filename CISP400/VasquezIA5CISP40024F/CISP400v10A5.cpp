// Name: Israel Vasquez
// Assignment#: A5
// File Name: CISP400v10A5.cpp
// Purpose: Main function to use complex.cpp and complex.h to output complex numbers in certain forms and opperations.
// Course: CISP 400 F24

#include <iostream>
#include "Complex.h"

using namespace std;

int main() {
    Complex x, y(4.3, 8.2), z(3.3, 1.1), k, l, m(0, 0.1);

    cout << "Enter a complex number in the form: (a, b) for Complex object k." << endl;
    cout << "(Performing >> operator overloading.)" << endl;
    cout << "? ";
    cin >> k;

    cout << "\nThe existing Complex objects are:\n(Performing << operator overloading.)";
    cout << "\nx: " << x << "\ny: " << y << "\nz: " << z << "\nk: " << k << "\nl: " << l << "\nm: " << m << '\n';

    cout << "\n\nPerforming +, = and << operators overloading.";
    x = y + z;
    cout << "\nx = y + z:\n" << x << " = " << y << " + " << z << '\n';

    cout << "\n\nPerforming *, = and << operators overloading.";
    x = y - z;
    cout << "\nx = y - z:\n" << x << " = " << y << " - " << z << '\n';

    cout << "\n\nPerforming /, = and << operators overloading.";
    x = y * z;
    cout << "\nx = y * z:\n" << x << " = " << y << " * " << z << '\n';

    try {
        cout << "\n\nPerforming /, = and << operators overloading with divisor is (0, 0).";
        x = y / z;
        cout << "\nx = y / z:\n" << x << " = " << y << " / " << z << '\n';
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << '\n';
    }

    try {
        cout << "\n\nPerforming /, = and << operators overloading with divisor is (0, 0).\n";
        x = y / l;
        cout << "x = y / l:\n" << x << " = " << y << " / " << l << '\n';
    }
    catch (const runtime_error& e) {
        cout << "x = y / l:\ninfinite = " << y << " / "<< l << "\n";
    }

    cout << "\n\nPerforming /, = and << operators overloading with divisor is (0, 0.1).";
    x = y / m;
    cout << "\nx = y / m:\n" << x << " = " << y << " / " << m << '\n';

    cout << "\n\nPerforming != and << operators overloading.\ncheck x != k" << endl;
    if (x != k)
        cout << x << " != " << k << '\n';

    cout << "\nPerforming =, == and << operators overloading.\nassign k to x by using x=k statement.\ncheck x == k" << endl;

    x = k;
    if (x == k)
        cout << x << " == " << k;

    return 0;
}
