/*
 14. Реализовать абстрактный базовый класс Число с виртуальной функцией
изменения знака числа. Создать производные классы: целое (int), вещественное (double)
и комплексное (float, float). Продемонстрировать пример работы с использованием
указателя на абстрактный базовый класс
*/

#include <iostream>

using namespace std;

class Number {
public:
    virtual void change_sign() = 0;

    virtual void disp() const = 0;

    virtual ~Number() = default;
};

class NumberInt : public Number {
private:
    int _value_int;
public:
    NumberInt(int val) : _value_int(val) {}

    void change_sign() override {
        _value_int *= -1;
    }

    void disp() const override {
        cout << "integer: " << _value_int << endl;
    }
};

class NumberDouble : public Number {
private:
    double _value_double;
public:
    NumberDouble(double val) : _value_double(val) {}

    void change_sign() override {
        _value_double *= -1;
    }

    void disp() const override {
        cout << "real: " << _value_double << endl;
    }
};

class NumberComplex : public Number {
private:
    float _real;
    float _imag;
public:
    NumberComplex(float var_r, float var_i) :
        _real(var_r), _imag(var_i) {}

    void change_sign() override {
        _real *= -1;
        _imag *= -1;
    }

    void disp() const override {
        if(_imag < 0)
            cout << "complex: " << _real << " - i" << _imag << endl;
        else
            cout << "complex: " << _real << " + i" << -_imag << endl;
    }
};

int main()
{
    Number* num_ptr[3];
    num_ptr[0] = new NumberInt(3);
    num_ptr[1] = new NumberDouble(5.7);
    num_ptr[2] = new NumberComplex(2.1, -8);

    cout << "До применения change_sign(): \n";
    for(int i = 0; i < 3; ++i)
        num_ptr[i]->disp();

    for(int i = 0; i < 3; ++i)
        num_ptr[i]->change_sign();

    cout << "После: \n";
    for(int i = 0; i < 3; ++i)
        num_ptr[i]->disp();

    for(int i = 0; i < 3; ++i)
        delete num_ptr[i];

    return 0;
}
