#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    BankAccount(const string& accNum, double initialBalance = 0.0)
        : accountNumber(accNum), balance(initialBalance) {}

    string getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }

    void setAccountNumber(const string& accNum) { accountNumber = accNum; }

    bool deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            return true;
        }
        return false;
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        cout << "Недостаточно средств или некорректная сумма!\n";
        return false;
    }
};

int main() {
    BankAccount account("123456789", 1000.0);
    cout << "Счёт: " << account.getAccountNumber() << ", баланс: " << account.getBalance() << " руб.\n";

    account.deposit(500);
    cout << "После пополнения: " << account.getBalance() << " руб.\n";

    account.withdraw(200);
    cout << "После снятия: " << account.getBalance() << " руб.\n";

    return 0;
}
