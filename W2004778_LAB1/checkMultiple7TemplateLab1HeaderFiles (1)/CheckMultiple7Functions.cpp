#include "CheckMultiple7Header.h"
#include <iostream>
#include <string>
using namespace std;


// Function to input an integer from the user
int inputNumber() {
    int num;
    cout << "Please enter an integer: ";
    cin >> num;
    return num;
}

// Function to check if a number is a multiple of 7
bool checkMultiple7(int num) {
    return num % 7 == 0;
}

// Function to display the results
void displayResults(int num, const string& message) {
    cout << num << " " << message << endl;
}

// Main function
void runNumberCheck() {
    int number = inputNumber();

    if (checkMultiple7(number)) {
        displayResults(number, "is a multiple of 7");
    }
    else {
        displayResults(number, "is not a multiple of 7");
    }
}


