#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate) : Savings_Account(
  name, balance, int_rate
) {
}

bool Trust_Account::deposit(double amount) {
  if (amount >= 5000) amount += 50;
  return Savings_Account::deposit(amount);
}

Trust_Account &Trust_Account::operator+=(const Trust_Account &rhs) {
    this->deposit(rhs.balance);
    return *this;
}

Trust_Account &Trust_Account::operator-=(const Trust_Account &rhs) {
    this->withdraw(rhs.balance);
    return *this;
}

bool Trust_Account::withdraw(double amount){
  if (this->withdrawl_start_count > 0 && amount >= 0.2 * this->balance){
    this->withdrawl_start_count--;
    return Savings_Account::withdraw(amount);
  }
  else return false;
}

std::ostream &operator<<(std::ostream &os, const Trust_Account &account) {
    os << "[Trust_Account: " << account.name << ": " << account.balance << ", " << account.int_rate << "%]";
    return os;
}
