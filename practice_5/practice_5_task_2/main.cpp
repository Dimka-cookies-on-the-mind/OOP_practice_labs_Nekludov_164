#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

    using namespace std;

class BankAccount {
protected:
    string ownerName;
    string accountNumber;
    double balance;

private:
    bool isValidAmount(double amount) const {
        return amount > 0 && amount <= balance;
    }

public:
    BankAccount(const string& owner, const string& number, double initialBalance = 0.0)
        : ownerName(owner), accountNumber(number), balance(initialBalance) {}

    bool deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            return true;
        }
        return false;
    }

    bool withdraw(double amount) {
        if (isValidAmount(amount)) {
            balance -= amount;
            return true;
        }
        cout << "Некорректная сумма для снятия!\n";
        return false;
    }

    void displayInfo() const {
        cout << "Владелец: " << ownerName << "\n"
             << "Номер счета: " << accountNumber << "\n"
             << "Баланс: " << fixed << setprecision(2) << balance << " руб.\n";
    }

    BankAccount& operator+=(double amount) {
        deposit(amount);
        return *this;
    }

    BankAccount& operator-=(double amount) {
        withdraw(amount);
        return *this;
    }

    bool operator>(const BankAccount& other) const {
        return balance > other.balance;
    }

    string getOwnerName() const { return ownerName; }
    string getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(const string& owner, const string& number,
                   double initialBalance, double rate)
        : BankAccount(owner, number, initialBalance), interestRate(rate) {}

    bool deposit(double amount) {
        if (amount > 0) {
            double interest = amount * interestRate / 100;
            balance += amount + interest;
            cout << "Начислены проценты: " << fixed << setprecision(2) << interest << " руб.\n";
            return true;
        }
        return false;
    }

    void displayInfo() const {
        BankAccount::displayInfo();
        cout << "Процентная ставка: " << interestRate << "%\n";
    }

    SavingsAccount operator+(SavingsAccount& other) {
        string newOwner = ownerName + " & " + other.ownerName;
        string newNumber = accountNumber + "-" + other.accountNumber;
        double newBalance = balance + other.balance;
        double avgRate = (interestRate + other.interestRate) / 2;

        balance = 0;
        other.balance = 0;

        return SavingsAccount(newOwner, newNumber, newBalance, avgRate);
    }
};

void processTransaction(BankAccount& account, double amount) {
    cout << "Пополнение счета " << account.getAccountNumber() << " на " << amount << " руб.\n";
    account += amount;
}

void processTransaction(BankAccount& from, BankAccount& to, double amount) {
    cout << "Перевод " << amount << " руб. со счета " << from.getAccountNumber()
        << " на счет " << to.getAccountNumber() << "\n";

    if (from.withdraw(amount)) {
        to.deposit(amount);
        cout << "Перевод выполнен успешно!\n";
    } else {
        cout << "Ошибка при выполнении перевода!\n";
    }
}

int main() {

    vector <BankAccount*> accounts = {
        new BankAccount ("ИвановИИ", "12345a", 1500),
        new BankAccount ("ПетровПП", "54321b"),
        new SavingsAccount ("СтепановСС", "13579c", 23000, 12),
        new SavingsAccount ("ИвановаЕП", "24680d", 14000, 11)};

    cout << "=== ИСХОДНОЕ СОСТОЯНИЕ СЧЕТОВ ===\n";
    for (const auto& account : accounts)
        account->displayInfo();

    cout << "\n=== ДЕМОНСТРАЦИЯ ПОЛИМОРФНОГО ПОВЕДЕНИЯ ===\n";
    for (auto& account : accounts) {
        account->deposit(500);
        account->withdraw(200);
        cout << "После операций:\n";
        account->displayInfo();
        cout << "---\n";
    }

    cout << "\n=== РАБОТА ПЕРЕГРУЖЕННЫХ ОПЕРАТОРОВ ===\n";
    *accounts [0] += 400;
    cout << "Счёту 12345a было применено += 400" << endl;
    accounts [0] -> displayInfo ();
    *accounts [3] -= 100;
    cout << "Счёт 24680d потерпел -= 100" << endl;
    accounts [3] -> displayInfo ();

    if (*accounts [0] > *accounts [3]) {
        cout << accounts [0] -> getAccountNumber () << " имеет больший баланс, чем "
             << accounts [3] -> getAccountNumber () << "\n";
    } else {
        cout << accounts [3] -> getAccountNumber () << " имеет больший баланс, чем "
             << accounts [0] -> getAccountNumber () << "\n";
    }

    cout << "\n=== ТЕСТИРОВАНИЕ ФУНКЦИЙ TRANSACTION ===\n";
    processTransaction(*accounts[0], 400);
    processTransaction(*accounts[1], *accounts[2], 300);

    cout << "\n=== ОБЪЕДИНЕНИЕ СБЕРЕГАТЕЛЬНЫХ СЧЕТОВ ===\n";

    SavingsAccount acc1 ("СемёнСС", "13243e", 12000, 20);
    SavingsAccount acc2 ("НовиковВВ", "34231f", 30000, 10);
    cout << "Начальные счета:\n";
    acc1.displayInfo();
    acc2.displayInfo();
    SavingsAccount acc3 = acc1 + acc2;
    cout << "Объединенный счет:\n";
    acc3.displayInfo();

    return 0;
}
