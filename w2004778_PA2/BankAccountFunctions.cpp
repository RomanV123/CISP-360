#include <string>
#include "BankAccountHeader.h"
#include <iostream>
#include <iomanip>

// Constructor to initialize member variables
BankAccount::BankAccount() {
    accountName = "";
    accountNumber = 0;
    accountBalance = 0;
    MIN_BALANCE = 9.99;
    REWARD_RATE = 1.04;
    MIN_REWARD_AMOUNT = 1000.00;
}

// Overloaded constructor to set initial values
BankAccount::BankAccount(std::string accountName, int accountNumber, double accountBalance) {
    this->accountNumber = accountNumber;
    this->accountName = accountName;
    this->accountBalance = accountBalance;
    MIN_BALANCE = 9.99;
    REWARD_RATE = 1.04;
    MIN_REWARD_AMOUNT = 1000.00;
}

// Getter for accountName
std::string BankAccount::getAccountName() {
    return accountName;
}

// Getter for accountNumber
int BankAccount::getAccountNumber() {
    return accountNumber;
}

// Getter for accountBalance
double BankAccount::getAccountBalance() {
    return accountBalance;
}

// Setter for accountBalance
void BankAccount::setAccountBalance(double amount) {
    accountBalance = amount;
}

// Convert the account information to a string
std::string BankAccount::toString() {
    
    std::cout << std::fixed << std::setprecision(2);        //to string that will display the information

    return "Account Name: " + (accountName)+"\n" + "Account Number: " + std::to_string(accountNumber) + "\n" + "Account Balance: $" + std::to_string(accountBalance) + "\n";
}

// Withdraw funds from the account
bool BankAccount::withdraw(double amount) {
    do {

        if (accountBalance < MIN_BALANCE) {

            std::cout << accountName << ": " << std::endl;
            std::cout << "Insufficient Funds!" << std::endl;        
            std::cout << std::endl;                                 
            // insufficient funds

            return true;

        }

        else {                                                    
            
            accountBalance -= amount;
            std::cout << accountName << ": " << std::endl;
            std::cout << "Remaining Balance: " << accountBalance << std::endl;;
            std::cout << std::endl;

        }

    } while (accountBalance < MIN_BALANCE);



}
// Deposit funds into the account and check for rewards
void BankAccount::deposit(double amount) {
    
    if (amount <= MIN_REWARD_AMOUNT) {
        accountBalance += amount; 
    }
    else {
        addReward(amount);
    }
}

// Add reward to the account balance
void BankAccount::addReward(double amount) {
    accountBalance += REWARD_RATE * amount;
}
