#include <iostream>

using namespace std;

class Number {
public:
    int value;

    Number (int val = 0): value (val) {}

    Number operator + (Number const& num2)const {
        return Number (value + num2.value);
    }

    Number operator - (Number const& num2)const {
        return Number (value - num2.value);
    }

    Number operator * (Number const& num2)const {
        return Number (value * num2.value);
    }

    friend ostream& operator << (ostream& outs, const Number& num) {
        outs << num.value;
        return outs;
    }
};

int main()
{
    Number n1 (3);
    Number n2 (7);

    Number n3 = n1 + n2;

    cout << "n1 = " << n1 << endl
         << "n2 = " << n2 << endl
         << "n3 = n1 + n2 = " << n3 << endl;

    return 0;
}
