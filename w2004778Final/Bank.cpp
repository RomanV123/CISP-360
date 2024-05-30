
#include "Bank.h"
#include <iostream>
#include <sstream>
#include <memory>
#include <algorithm>
#include "GreaterThan.h"
void fillVector(ifstream &input, vector<shared_ptr<UserAccount>>& accountsVector) {
    string inputLine, firstName, lastName, type;
    int id, accountNumber;
    double accountBalance;

    while (!input.eof()) {
      getline(input, inputLine);
           
      istringstream streamLine(inputLine);
      if (streamLine >> firstName >> lastName >> id >> accountNumber >> accountBalance >> type) {
        string accountName = firstName + " " + lastName;
        shared_ptr<UserAccount> account;

        if (type == "S") {
          account = make_shared<SavingsAccount>(accountName, id, accountNumber, accountBalance);
        } 
        else if (type == "C") {
          account = make_shared<CheckingAccount>(accountName, id, accountNumber, accountBalance);
        } 
        else {
          cout << "Unknown Account Type: " << type << endl;
          continue;
        }
        accountsVector.push_back(account);
      } 
    }
}

              
  //while not eof getline from file
  // parse the line and create shared pointer to BankAccount
  //push the pointe onto the accounts vector
  

void Bank::displayAccounts(){
  
  for (int i=0;i<accountsVector.size();i++){
    cout<<accountsVector[i]->toString()<<endl;
  }
}
Bank::Bank(const Bank &other){
  cout<<" In copy constructor  "<<endl;
  for (const auto& account : other.accountsVector) {
      accountsVector.push_back(account);
  }

 
}


Bank::Bank(string filename){
  try{
    ifstream input(filename);
    if(!input.is_open()) {
      throw FileException(-99);
    }  
    fillVector(input, accountsVector);
  }
  catch(FileException& e) {
    cout << "File Open Error " << e.getValue() << endl;
    exit(0);
  }
 // throw File Open Error - File Exception -99 if file cannot be opened
//use try catch statement
}

void Bank::addAccount(shared_ptr<UserAccount> a){
  accountsVector.push_back(a);
  sortAccounts();
//should sort vector
  //add an account
  // be sure to keep vector sorted
//use STL sort using Greater THan Function Object
}

void Bank::sortAccounts(){
  sort(accountsVector.begin(), accountsVector.end(), GreaterThan());
  // use the STL sort by passing the beginning, end and Greater Than Functor
}

bool Bank::accountDeposit(shared_ptr<UserAccount> a, double amount){
  if (amount <= 0) {
    return false;
  }
  a->deposit(amount);
  return true;
 // return false if amount is negative
 // return true after depositing into account
}

bool Bank::accountWithdraw(shared_ptr<UserAccount> a, double amount){
  if (amount <= 0) {
    return false;
  }
  return a->withdraw(amount);
  // if the withdraw amount is suitable then withdraw from account and return true
  
 //otherwise return false
}

bool Bank::checkSame( Bank &other){
  if (accountsVector.size() != other.accountsVector.size()) {
    return false;
  }
  
  int index = 0;
  for (auto& account: accountsVector) {
    if (!account->equalTo(other.accountsVector[index])) {
      return false;
    }
    ++index;
  }
  
  return true;
}




bool Bank::removeAccount(shared_ptr<UserAccount> a){
  for (auto it = accountsVector.begin(); it != accountsVector.end(); ++it) {
    if (a->equalTo(*it)) {
      accountsVector.erase(it);
      return true;
    }
  }
  return false;
}
  

  //search for the the given account a, if found
  //use vector.erase method to remove it and return true
  //otherwise return false

