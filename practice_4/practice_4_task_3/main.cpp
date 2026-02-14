//практика 4 задание 3

#include <iostream>

using namespace std;

class Complex {
private:
    double m_real;
    double m_imaginary;
public:
    Complex(double real = 0, double imaginary = 0) : m_real(real), m_imaginary(imaginary) {}

    Complex operator + (const Complex& other) const {
        return Complex(m_real + other.m_real, m_imaginary + other.m_imaginary);
    }

    Complex operator - (const Complex& other) const {
        return Complex(m_real - other.m_real, m_imaginary - other.m_imaginary);
    }

    Complex operator * (const Complex& other) const {
        return Complex(m_real * other.m_real - m_imaginary * other.m_imaginary,
            m_real * other.m_imaginary + m_imaginary * other.m_real);
    }

    Complex operator ~ () const {
        return Complex(m_real, -m_imaginary);
    }

    friend ostream& operator << (ostream& os, const Complex& z) {
        if(z.m_imaginary >= 0)
            os << z.m_real << " + " << z.m_imaginary << "i";
        else
            os << z.m_real << " - " << -z.m_imaginary << "i";
        return os;
    }
};

int main()
{
    Complex z1(7, 8);
    Complex z2(3, 5);
    cout << "z1 = " << z1 << endl << "z2 = " << z2 << endl
         << "z1 + z2 = " << z1 + z2 << endl << "z1 - z2 = "
         << z1 - z2 << endl << "z1 * z2 = " << z1 * z2 << endl
         << "~z1 = " << ~z1 << endl;

    return 0;
}
