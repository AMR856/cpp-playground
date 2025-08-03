// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;

    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account{});
    accounts.push_back(Account{"Larry"});
    accounts.push_back(Account{"Moe", 2000});
    accounts.push_back(Account{"Curly", 5000});

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);

    // += and -= with Account
    accounts[0] += accounts[1];  // Deposit balance of accounts[1] into accounts[0]
    accounts[1] -= accounts[2];  // Withdraw balance of accounts[2] from accounts[1]

    // Savings Accounts
    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account{});
    sav_accounts.push_back(Savings_Account{"Superman"});
    sav_accounts.push_back(Savings_Account{"Batman", 2000});
    sav_accounts.push_back(Savings_Account{"Wonderwoman", 5000, 5.0});

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);

    // += and -= with Savings_Account
    sav_accounts[0] += sav_accounts[1];
    sav_accounts[1] -= sav_accounts[2];

    // Checking Accounts
    vector<Checking_Account> check_accounts;
    check_accounts.push_back(Checking_Account{});
    check_accounts.push_back(Checking_Account{"Kirk"});
    check_accounts.push_back(Checking_Account{"Spock", 2000});
    check_accounts.push_back(Checking_Account{"Bones", 5000});

    display(check_accounts);
    deposit(check_accounts, 1000);
    withdraw(check_accounts, 2000);  // $1.50 fee per withdrawal

    // += and -= with Checking_Account
    check_accounts[0] += check_accounts[1];
    check_accounts[1] -= check_accounts[2];

    // Trust Accounts
    vector<Trust_Account> trust_accounts;
    trust_accounts.push_back(Trust_Account{});
    trust_accounts.push_back(Trust_Account{"Athena"});
    trust_accounts.push_back(Trust_Account{"Hercules", 10000, 5.0});
    trust_accounts.push_back(Trust_Account{"Odysseus", 20000, 4.0});

    display(trust_accounts);
    deposit(trust_accounts, 1000);      // Regular deposit
    deposit(trust_accounts, 5000);      // Bonus $50
    withdraw(trust_accounts, 1000);     // OK
    withdraw(trust_accounts, 1000);     // OK
    withdraw(trust_accounts, 1000);     // OK
    withdraw(trust_accounts, 1000);     // Should fail - more than 3 withdrawals

    // += and -= with Trust_Account
    trust_accounts[0] += trust_accounts[1];
    trust_accounts[1] -= trust_accounts[2];

    return 0;
}
