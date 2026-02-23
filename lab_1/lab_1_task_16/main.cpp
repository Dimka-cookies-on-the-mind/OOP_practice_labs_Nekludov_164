
//задание 16 из {2, 8, 11, 16}

#include <iostream>

using namespace std;

class Complex {
private:
    float m_r;
    float m_i;

public:
    Complex(float r = 0.0, float i = 0.0): m_r(r), m_i(i) {}

    void read() {
        cout << "Введите следующее:" << endl << " Re = ";
        cin >> m_r;
        cout << " Im = ";
        cin >> m_i;
    }

    void display() {
        if(m_i >= 0)
            cout << m_r << " + i" << m_i << endl;
        else
            cout << m_r << " - i" << -m_i << endl;
    }

    Complex add(const Complex& other) const {
        return Complex(m_r + other.m_r, m_i + other.m_i);
    }

    Complex subtract(const Complex& other) const {
        return Complex(m_r - other.m_r, m_i - other.m_i);
    }

    Complex multiply(const Complex& other) const {
        double realPart = m_r * other.m_r - m_i * other.m_i;
        double imagPart = m_r * other.m_i + m_i * other.m_r;
        return Complex(realPart, imagPart);
    }

    Complex divide(const Complex& other) const {
        double denominator = other.m_r * other.m_r + other.m_i * other.m_i;
        if (denominator == 0) {
            cout << "Ошибка: деление на ноль\n";
            return Complex(0, 0);
        }
        double realPart = (m_r * other.m_r + m_i * other.m_i) / denominator;
        double imagPart = (other.m_r * m_i - m_r * other.m_i) / denominator;
        return Complex(realPart, imagPart);
    }

};

int main()
{
    Complex z1, z2(5, 7);
    cout << "Введите значения z1:\n";
    z1.read();

    cout << "z1 = ";
    z1.display();
    cout << "z2 = ";
    z2.display();

    cout << "z1 + z2 = ";
    z1.add(z2).display();

    cout << "z1 - z2 = ";
    z1.subtract(z2).display();

    cout << "z1 * z2 = ";
    z1.multiply(z2).display();

    cout << "z1 / z2 = ";
    z1.divide(z2).display();

    return 0;
}
