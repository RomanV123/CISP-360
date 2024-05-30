#include <string>
#include <iostream>
#include "BankAccount1.h"

     // BankAccount::BankAccount();

      BankAccount::BankAccount(std::string accountName, int id, int accountNumber, double accountBalance){
        this->id=id;
        this->accountNumber=accountNumber;
        this->accountName=accountName;
        this->accountBalance=accountBalance;

      }

      int BankAccount::count = 0;

      BankAccount::BankAccount()
      {
          accountName = " ";
          accountNumber = 0;
          accountBalance = 0;
      }
       //getters
      
      std::string BankAccount::getAccountName()
      {
          return accountName;
      }
      

      int BankAccount::getAccountNumber()
      {
          return accountNumber;
      }
     

      double BankAccount::getAccountBalance()
      {
          return accountBalance;
      }
     

      int BankAccount::getCount()
      {
          return count;
      }

      std::string fixPoint(std::string number)
      {
          int i = number.find('.');
          return number.substr(0, i + 3);
      }

      std::string BankAccount::toString()
      {
          return "Account Name: " + accountName + "\n" +
              "Account Number: " + std::to_string(accountNumber) + "\n" +
              "Account Balance: " + fixPoint(std::to_string(accountBalance)) + "\n";
            
      }

      bool BankAccount::withdraw(double amount)
      {
          if (accountBalance - amount > MIN_BALANCE)
          {
              accountBalance -= amount;
              return true;
          }
          else
              return false;
      }
      

      void BankAccount::deposit(double amount)
      {
          accountBalance += amount;
          if (amount > MIN_REWARD_AMOUNT)
              addReward(amount);
      }
     

      void BankAccount::setAccountName(const std::string& newName)
      {
          accountName = newName;
      }
      

      void BankAccount::setId(int newId)
      {
          id = newId;
      }
      void BankAccount::setNumber(int newNumber)
      {
          accountNumber = newNumber;
      }
      

      void BankAccount::setAccountBalance(double accountBalance)
      {
          this->accountBalance = accountBalance;
      }
      

      void BankAccount::addReward(double amount)
      {
          accountBalance += accountBalance + REWARD_RATE * amount;
      }
      

      int BankAccount::getId()
      {
          return id;
      }
      

      bool BankAccount::equals(BankAccount other)
      {
          return (this->accountName == other.accountName) && (this->id == other.id);
          return  true;
      }
     

  const double BankAccount::MIN_BALANCE=9.99;
  const double BankAccount::MIN_REWARD_AMOUNT=1000.0;
  const double BankAccount::REWARD_RATE=0.04;