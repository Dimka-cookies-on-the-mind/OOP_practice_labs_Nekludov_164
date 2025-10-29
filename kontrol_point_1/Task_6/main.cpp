
#include <iostream>

using namespace std;

int Cash = 1000;

class Account {
private:
    int AccNumber;
    int Balance;
public:
    void SetAccNumber (int NewAccNumber) {
        AccNumber = NewAccNumber;
    }
    void SetBalance (int NewBalance) {
        Balance = NewBalance;
    }
    int GetAccNumber () {
        return AccNumber;
    }
    int GetBalance () {
        return Balance;
    }
    void Deposit (int HowMuch) {
        if (Cash >= HowMuch) {
            Balance += HowMuch;
            Cash -= HowMuch;
        }
        else {
            cout << "Ошибка" << endl;
        }
    }
    void Withdraw (int HowMuch) {
        if (Balance >= HowMuch) {
            Balance -= HowMuch;
            Cash += HowMuch;
        }
        else {
            cout << "Ошибка" << endl;
        }
    }

    Account (int AccountNumber) : AccNumber (AccountNumber), Balance (0) {}
};

int main()
{
    Account User1 (374628);
    cout << "У пользователя банка с номером счёта " << User1.GetAccNumber() << " баланс составляет: " <<
        endl << User1.GetBalance() << endl << "Сколько бы Вы ему добавили средств? " << endl << "Введите: ";
    int Buf = 0;
    cin >> Buf;
    User1.SetBalance(User1.GetBalance() + Buf);
    cout << "Теперь его баланс: " << endl << User1.GetBalance() << endl <<
        "Оказалось, у него есть наличка, а рядом банкомат. Он положил эти деньги на карту. " << endl;
    User1.Deposit(Cash);
    cout << "На его счету теперь: " << endl << User1.GetBalance();

    return 0;
}
