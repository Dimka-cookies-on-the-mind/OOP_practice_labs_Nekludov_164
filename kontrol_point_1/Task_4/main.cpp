#include <iostream>

using namespace std;

int el_num = 0; //глобальная переменная, да, простите
int el_num_der = 0; //и ещё одна
class BaseClass {
public:
    int val;
    BaseClass () {
        el_num += 1;
        cout << "Сработал конструктор базового класса " << el_num << "-го элемента" << endl;
        cout << "(без аргументов)" << endl;
    }
    BaseClass (int SomeVal): val (SomeVal) {
        el_num += 1;
        cout << "Сработал конструктор базового класса " << el_num << "-го элемента" << endl;
        cout << "(с аргументом " << SomeVal << ")" << endl;
    }
    ~BaseClass () {
        cout << "Сработал деструктор базового класса " << el_num << "-го элемента" << endl;
        el_num --;
    }
};

class DerivedClass : public BaseClass {
public:
    DerivedClass () {
        el_num_der ++;
        cout << "Сработал конструктор производного класса " << el_num_der << "-го элемента" << endl;
        cout << "(без аргументов)" << endl;
    }
    DerivedClass (int SomeVal): BaseClass (SomeVal) {
        el_num_der ++;
        cout << "Сработал конструктор производного класса " << el_num_der << "-го элемента" << endl;
        cout << "(с аргументом " << SomeVal << ")" << endl;
    }
    ~DerivedClass () {
        cout << "Сработал деструктор производного класса " << el_num_der << "-го элемента" << endl;
        el_num_der --;
    }
};

int main()
{
    cout << "Hello World!" << endl;
    BaseClass a;
    BaseClass b (10);
    DerivedClass c;
    DerivedClass d (11);
    return 0;
}
