#include "./Checking_Account.h"
#include "Checking_Account.h"

// Checking_Account(std::string name = def_name, double balance = def_balance);
Checking_Account::Checking_Account(std::string name, double balance) : Account(
  name, balance) {
}

bool Checking_Account::withdraw(double amount) {
  if (this->balance - amount - this->flat_fee >= 0){
    this->balance -= (amount + this->flat_fee);
    return true;
  } else
    return false;
}

Checking_Account &Checking_Account::operator+=(const Checking_Account &rhs) {
  this->deposit(rhs.balance);
  return *this;
}

Checking_Account &Checking_Account::operator-=(const Checking_Account &rhs) {
  this->withdraw(rhs.balance);
  return *this;
}

std::ostream &operator<<(std::ostream &os, const Checking_Account &account)
{
  os << "[Checking_Account: " << account.name << ": " << account.balance << ", " << account.flat_fee << "%]";
  return os;
}
