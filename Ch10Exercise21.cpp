// Charles Edge
// CS310-T301
// M9: Assignment
// Source CH11, Programming Exercise 13

#include <iostream>
using namespace std;

// This is the Parent Class
class bankAccount {
protected:
    int accountNo;
    double bal;
public:
    bankAccount(int accNum = 0, double bal = 0.0) : accountNo(accNum), bal(bal) {}

// Set it and get it account number
    void setAccountNumber(int accNum) { accountNo = accNum; }
    int getAccountNumber() const { return accountNo; }

// Gets current balance
    double getBalance() const { return bal; }
    void deposit(double amount) { bal += amount; }
    virtual void withdraw(double amount) { if (amount <= bal) bal -= amount; }

// Print account details
    virtual void printAccountInfo() const {
        cout << "Account Number: " << accountNo << ", Available Balance: $" << bal << endl;
    }
};

// Checking Account Class
class checkingAccount : public bankAccount {
private:
    double interestRate;
    double minBalance;
    double serviceCharge;
public:
    checkingAccount(int accNum = 0, double bal = 0.0, double rate = 0.0, double minBal = 0.0, double charge = 0.0)
        : bankAccount(accNum, bal), interestRate(rate), minBalance(minBal), serviceCharge(charge) {
    }
    void setInterestRate(double rate) { interestRate = rate; }
    double getInterestRate() const { return interestRate; }
    void setMinBalance(double minBal) { minBalance = minBal; }
    double getMinBalance() const { return minBalance; }
    void setServiceCharge(double charge) { serviceCharge = charge; }
    double getServiceCharge() const { return serviceCharge; }
    void postInterest() { bal += bal * interestRate; }
    bool belowMinBalance() const { return bal < minBalance; }
    void writeCheck(double amount) { withdraw(amount); }
    void withdraw(double amount) override {
        if (amount <= bal) {
            bal -= amount;
            if (belowMinBalance()) bal -= serviceCharge;
        }
    }

// Print Checking Account details
    void printAccountInfo() const override {
        bankAccount::printAccountInfo();
        cout << "Interest (%): " << interestRate
            << endl
            << "Min Balance: $" << minBalance
            << endl
            << "Service Charge: $" << serviceCharge << endl;
        cout << endl;
    }
};

// Savings Account Class
class savingsAccount : public bankAccount {
private:
    double interestRate;
public:
    savingsAccount(int accNum = 0, double bal = 0.0, double rate = 0.0)
        : bankAccount(accNum, bal), interestRate(rate) {
    }
    void setInterestRate(double rate) { interestRate = rate; }
    double getInterestRate() const { return interestRate; }
    void postInterest() { bal += bal * interestRate; }
    void withdraw(double amount) override {
        if (amount <= bal) bal -= amount;
    }

// Print Savings Account details
    void printAccountInfo() const override {
        bankAccount::printAccountInfo();
        cout << "Interest Rate (%): " << interestRate << endl;
    }
};

// Testing part of program, contains static balance
int main() {
    checkingAccount chk(5000, 1500.0, 0.035, 100.0, 15.0);
    savingsAccount sav(5001, 1250.0, 0.025);

// Checking Account
    cout << "*************************" << endl;
    cout << "     Checking Account    " << endl;
    cout << "*************************" << endl;
    chk.deposit(150);
    chk.writeCheck(175);
    chk.postInterest();
    chk.printAccountInfo();

// Savings Account
    cout << "*************************" << endl;
    cout << "     Savings Account     " << endl;
    cout << "*************************" << endl;
    sav.deposit(400);
    sav.withdraw(300);
    sav.postInterest();
    sav.printAccountInfo();

    return 0;
}
