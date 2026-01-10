#include <iostream>
#include <string>
using namespace std;
class BankAccount {
protected:
    string accountHolder;
    double balance;
public:
    // Constructor
    BankAccount(string name, double initialBalance) {
        cout << "BankAccount Constructor called." << endl;
        if (initialBalance < 0) {
            throw "Error: Initial balance cannot be negative.";
        }
        accountHolder = name;
        balance = initialBalance;
        cout << "Account created for " << accountHolder << endl;
    }
    // Withdraw function
    void withdraw(double amount) {
        cout << "Attempting withdrawal..." << endl;

        if (amount > balance) {
            throw "Error: Withdrawal amount exceeds available balance.";
        }
         balance -= amount;
        cout << "Withdrawal successful. Remaining balance: " << balance << endl;
    }
    // Destructor
    ~BankAccount() {
        cout << "BankAccount Destructor called for " << accountHolder << endl;
    }
};
int main() {
    /*-------- Case 1: Negative Balance Exception -------- */
    try {
        BankAccount* acc1 = new BankAccount("Ali", -500);
        delete acc1;   // will never execute
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
    cout << "-----------------------------------" << endl;
    /* -------- Case 2: Withdrawal Exception -------- */
    BankAccount* acc2 = nullptr;
    try {
        acc2 = new BankAccount("Sohaib", 500);
        acc2->withdraw(200);
        acc2->withdraw(400);   // throws exception
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
    // Safe cleanup
    if (acc2 != nullptr) {
        delete acc2;
        acc2 = nullptr;
    }
    cout << "Program ended safely." << endl;
    return 0;
}
