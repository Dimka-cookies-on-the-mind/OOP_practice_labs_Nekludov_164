#include <iostream>

using namespace std;

class Fraction {
private:
    int _numerator;  //числитель
    int _denominator;  //знаменатель
public:
    Fraction(int numerator, int denominator) :
        _numerator(numerator), _denominator(denominator) {}

    bool operator > (Fraction const& other) const {
        return (double)_numerator / _denominator > (double)other._numerator / other._denominator;
    }

    bool operator < (Fraction const& other) const {
        return (double)_numerator / _denominator < (double)other._numerator / other._denominator;
    }

    friend bool operator == (Fraction const& first, Fraction const& second);
};

bool operator == (Fraction const& first, Fraction const& second) {
    return (double)first._numerator / first._denominator == (double)second._numerator / second._denominator;
}

int main()
{
    Fraction drobij1(5, 9);
    Fraction drobij2(2, 7);
    cout << "Есть дроби 5/9 и 2/7 \n";
    cout << "Сейчас будет применён условный оператор, с помощью " <<
            "которого будет выведено правильное утверждение о том, " <<
            "какая дробь больше: \n";
    if(drobij1 > drobij2)
        cout << "5/9 > 2/7" << endl;
    else if(drobij1 < drobij2)
        cout << "5/9 < 2/7" << endl;
    else
        cout << "Дроби равны" << endl;

    cout << "Явное использование перегруженного оператора \"==\": \n";
    if(drobij1 == drobij2)
        cout << "Дроби равны" << endl;
    else
        cout << "Дроби не равны" << endl;

    return 0;
}
