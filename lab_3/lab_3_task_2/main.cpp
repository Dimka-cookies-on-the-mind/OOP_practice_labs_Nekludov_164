#include <iostream>

using namespace std;

class Maximum {
public:
    int Calculate(int a1, int a2) {
        if(a1 > a2)
            return a1;
        else
            return a2;
    }

    double Calculate(double b1, double b2) {
        if(b1 > b2)
            return b1;
        else
            return b2;
    }

    char Calculate(char c1, char c2) {
        if(c1 > c2)
            return c1;
        else
            return c2;
    }

};

int main()
{
    int i1 = 3, i2 = 4;
    double d1 = 5.1, d2 = 5.5;
    char ch1 = 'a', ch2 = 'b';
    Maximum max;
    cout << "Имеются переменные со следующими типами и значениями: \n";
    cout << "int i1 = " << i1 << endl;
    cout << "int i2 = " << i2 << endl;
    cout << "double d1 = " << d1 << endl;
    cout << "double d2 = " << d2 << endl;
    cout << "char ch1 = " << ch1 << endl;
    cout << "char ch2 = " << ch2 << endl;
    cout << "Имеется объект класса Maximum max \n";
    cout << "Операция Calculate объекта max над ними: \n";
    cout << "max.Calculate(i1, i2) = " << max.Calculate(i1, i2) << endl;
    cout << "max.Calculate(d1, d2) = " << max.Calculate(d1, d2) << endl;
    cout << "max.Calculate(ch1, ch2) = " << max.Calculate(ch1, ch2) << endl;

    return 0;
}
