#include "Account.h"

Account::Account(std::string name, double balance) 
    : name{name}, balance{balance} {
}

bool Account::deposit(double amount) {
    if (amount < 0) 
        return false;
    else {
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount) {
    if (balance-amount >=0) {
        balance-=amount;
        return true;
    } else
        return false;
}

double Account::get_balance() const {
    return balance;
}

Account &Account::operator+=(const Account &rhs) {
    this->deposit(rhs.balance);
    return *this;
}

Account &Account::operator-=(const Account &rhs) {
    this->withdraw(rhs.balance);
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Account &account) {
    os << "[Account: " << account.name << ": " << account.balance << "]";
    return os;
}
