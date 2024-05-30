#pragma once
#include "UserAccount.h" 
//#include "Helper.h"        
class SavingsAccount: public UserAccount{
  //const static  double  MIN_BALANCE;
  
  public:
      SavingsAccount();
      SavingsAccount(std::string accountName, int id,int accountNumber, double accountBalance);
      virtual string toString() override;
      virtual bool withdraw(double amount) override;
      virtual void deposit(double amount) override;
      //virtual bool operator==(shared_ptr<SavingsAccount> a );
};