
#include "UserAccount.h"
//#include "Helper.h"
 #include <cstdlib>
 #include <memory>
 #include <vector>
 #include<iostream>

UserAccount::UserAccount(){
  this->id=0;
  this->accountBalance=0;

  this->accountName="";
         
}

UserAccount::UserAccount(std::string accountName, int id, int accountNumber, double accountBalance)
: accountNumber(accountNumber), id(id), accountName(accountName), accountBalance(accountBalance) {}
      
       //getters
      
std::string UserAccount::getAccountName(){
 return accountName;
         //
}
int UserAccount::getAccountNumber(){
  return accountNumber;
          //
}
double UserAccount::getAccountBalance(){
  return accountBalance;
          //
}
      // setters : cannot change number and accountName
      //setting balance may be needed by admin

void UserAccount::setAccountBalance(double accountBalance){
  this->accountBalance = accountBalance;
        //
}
      //helper method
std::string UserAccount::fixPoint(std::string number){
  int i= number.find('.');
  return number.substr(0,i+3);
}
     
bool UserAccount::equalTo (shared_ptr<UserAccount> a ) {
  return accountNumber == a->accountNumber && id == a->id &&
         accountName == a->accountName && accountBalance == a->accountBalance;
}



        // compare all fields of this user account with a
      
std::string UserAccount::toString(){
        //std::cout<<fixPoint(std::to_string(accountBalance));
  return "Account Name: "+accountName+"\n"+
         "Account Number: "+std::to_string(accountNumber)+"\n"+
         "Account Balance: " +fixPoint(std::to_string(accountBalance))+"\n"
          ;
                
}
void UserAccount::setAccountName(string accountName){
  this->accountName = accountName;
         //
}
void UserAccount::setAccountNumber(int number){
  this->accountNumber = number;
          //
}
        
void UserAccount::setId(int id){
  this->id = id;
          //
}
bool UserAccount::withdraw(double amount){
  if (amount <= 0) {
    return false;
  }
  if (accountBalance - amount < MIN_BALANCE) {
    return false;
  }
  accountBalance -= amount;
  return true;
}

      
      
void UserAccount::deposit(double amount){
  if (amount <= 0){
    return; 
  }

  accountBalance += amount;

  if (amount >= MIN_REWARD_AMOUNT) {
    addReward(amount);
  }
        // deposit and
        //check if eligible for reward
}
      
     
void  UserAccount::addReward(double amount){
  accountBalance = accountBalance+REWARD_RATE*amount;
}

int UserAccount::getId(){
  return id;
        //
}
     

  const double UserAccount::MIN_BALANCE=9.99;
  const double UserAccount::MIN_REWARD_AMOUNT=1000.0;
  const double UserAccount::REWARD_RATE=0.04;
