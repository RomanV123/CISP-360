#include <iostream>
#include "BankAccountHeader.h"
#include <iomanip>
#include <string>//bad practice to include cpp files
using namespace std;
int main() {
  
  
  BankAccount one("Matilda Patel", 1232,-4.00);
  BankAccount two("Fernando Diaz", 1234, 250);
  BankAccount three("Howard Chen", 1236,194.56);
  
  cout<<one.toString()<<endl;
  cout<<two.toString()<<endl;
  cout<<three.toString()<<endl;
 
  
  two.deposit(999);
  three.deposit(1000.25);
  
  cout<<two.toString()<<endl;
  cout<<three.toString()<<endl;

  if (one.withdraw(10000))
    cout<<"Remaing Balance :" <<one.getAccountBalance()<<endl;
  else 
    cout<<"Insufficient funds"<<endl;
  if (two.withdraw(90))
    cout<<"Remaining Balance :" <<two.getAccountBalance()<<endl;
  else 
    cout<<"Insufficient funds"<<endl;
  cout<<"Total Amounts :" <<one.getAccountBalance()+two.getAccountBalance()+three.getAccountBalance();
}