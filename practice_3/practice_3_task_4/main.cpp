#include <iostream>

using namespace std;

class BaseClass {
private:
    int value_;
public:
    BaseClass(int value = 0) : value_(value) {
        cout << "Вызван конструктор базового класса" << endl;
    }

    ~BaseClass() {
        cout << "Вызван деструктор базового класса" << endl;
    }
};

class DerivedClass : public BaseClass{
private:
    int der_val_;
public:
    DerivedClass(int val = 0, int der_val = 0) :
        BaseClass(val), der_val_(der_val) {
        cout << "Вызван конструктор производного класса" << endl;
    }

    ~DerivedClass() {
        cout << "Вызван деструктор производного касса" << endl;
    }
};

int main()
{
    cout << "В мейне создан объект производного класса" << endl;
    DerivedClass obj;
    return 0;
}
