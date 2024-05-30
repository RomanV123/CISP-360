
 #include "CheckingAccount.h"
 //#include "Helper.h"
 #include<iostream>
 CheckingAccount::CheckingAccount(){
         //
}

CheckingAccount::CheckingAccount(std::string accountName, int id, int accountNumber, double accountBalance)
: UserAccount(accountName, id, accountNumber, accountBalance) {}

 string CheckingAccount::toString(){
    return  "Account Name: "+getAccountName()+"\n"+
               "Account Number: "+std::to_string(getAccountNumber())+"\n"+
               "Account Balance: "+fixPoint(std::to_string(getAccountBalance()))+"\n"
               +
               "Account Type: Checking \n";
     }
bool CheckingAccount::withdraw(double amount){
  if (amount <= 0) {
    return false;
  }
  if (getAccountBalance() - amount < MIN_BALANCE_CHECKING) {
    return false;
  }

  setAccountBalance(getAccountBalance() - amount);
  return true;
  
      //
}
 
void CheckingAccount::deposit(double amount){
  if (amount <= 0) {
    return;
  }
  setAccountBalance(getAccountBalance() + amount);
}
 //
const  double  CheckingAccount::MIN_BALANCE_CHECKING=99.99;

