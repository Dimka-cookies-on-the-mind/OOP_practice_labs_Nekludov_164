#include <iostream>

using namespace std;

class Rate {
protected:
    float _mins_cost;
    float _sms_cost;
public:
    Rate (float mins_cost, float sms_cost) :
        _mins_cost (mins_cost), _sms_cost (sms_cost) {}

    void read () {
        cout << "Введите стоимость одной минуты звонка: ";
        cin >> _mins_cost;
        cout << "Введите стоимость отправки SMS: ";
        cin >> _sms_cost;
    }

    void display () const {
        cout << "Стоимость одной минуты звонка: " << _mins_cost << endl;
        cout << "Стоимость отправки SMS: " << _sms_cost << endl;
    }
};

class Phone : public Rate {
private:
    float _balance;
public:
    Phone (float mins_cost, float sms_cost, float balance) :
        Rate (mins_cost, sms_cost), _balance (balance) {}

    void call () {
        if (_balance >= _mins_cost) {
            _balance -= _mins_cost;
            cout << "Произошёл звонок " << endl;
            cout << "Баланс: " << _balance << endl;
        }
        else {
            cout << "На счёте недостаточно средств, чтобы позвонить " << endl;
        }
    }

    void sms () {
        if (_balance >= _sms_cost) {
            _balance -= _sms_cost;
            cout << "Произошла отправка SMS " << endl;
            cout << "Баланс: " << _balance << endl;
        }
        else {
            cout << "На счёте недостаточно средств, чтобы отправить SMS " << endl;
        }
    }

    void read () {
        Rate::read();
        cout << "Введите баланс: ";
        cin >> _balance;
    }

    void display () const {
        Rate::display();
        cout << "Баланс: " << _balance << endl;
    }
};

int main()
{
    Rate tarif (3.1, 2.2);
    Phone mobila (3.2, 1.2, 231.9);
    cout << "У меня есть некий тариф: " << endl;
    tarif.display ();
    cout << "И есть некий телефон: " << endl;
    mobila.display ();
    int choice = 0;
    cout << "Если хотите поменять что-то у телефона, нажмите 1 (нет - 0): ";
    cin >> choice;
    if (choice == 1) {
        mobila.read ();
        cout << "Обновлённая информация о телефоне: " << endl;
        mobila.display ();
    }
    cout << "Попытка позвонить с этого телефона: " << endl;
    mobila.call ();
    cout << "Попытка отправить SMS: " << endl;
    mobila.sms();

    return 0;
}
