#pragma once
#include "UserAccount.h"
 class CheckingAccount: public UserAccount{
   public:
const static  double  MIN_BALANCE_CHECKING;
public:
  CheckingAccount();  
  CheckingAccount(std::string accountName, int id,int accountNumber, double accountBalance);
  virtual string toString() override;
  virtual bool withdraw(double amount) override;
   virtual void deposit(double amount) override;
   //virtual bool operator==(shared_ptr<CheckingAccount> a );
};