

#ifndef _TRUST_ACCOUNT_H
#define _TRUST_ACCOUNT_H
#include "./Savings_Account.h"


class Trust_Account: public Savings_Account {
    friend std::ostream &operator<<(std::ostream &os, const Trust_Account &account);
private:
    static constexpr const char *def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    int withdrawl_start_count = 3;
public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);    
    bool withdraw(double amount);
    bool deposit(double amount);
    Trust_Account& operator+=(const Trust_Account& rhs);
    Trust_Account& operator-=(const Trust_Account& rhs);
};

#endif // _TRUST_ACCOUNT_H
