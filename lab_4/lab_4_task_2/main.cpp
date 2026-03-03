#include <iostream>
#include <vector>

using namespace std;

class Complex {
private:
    int _real;
    int _imag;
public:
    Complex(int real = 0, int imag = 0) : _real(real), _imag(imag) {}

    void read() {
        cout << "Re = "; cin >> _real;
        cout << "Im = "; cin >> _imag;
    }

    void display() {
        cout << "Re = " << _real;
        cout << "Im = " << _imag;
    }

    void operator += (const Complex& second) {
        _real += second._real;
        _imag += second._imag;
    }

    Complex operator / (const size_t operand) {
        return Complex(_real/operand, _imag/operand);
    }

    friend ostream& operator << (ostream& outs, const Complex& z) {
        if(z._imag >= 0) {
            outs << z._real << "+i" << z._imag;
        }
        else {
            outs << z._real << "-i" << -z._imag;
        }
        return outs;
    }
};

template <class T>
T arithm_mean(const vector<T>& vec) {
    T sum = 0;
    for(const T elem : vec) {
        sum += elem;
    }
    return sum / vec.size();
}

int main()
{
    vector<int> int_v = {3, 2, 45, 7, 1};
    vector<double> double_v = {3.5, 7.54, 4.12, 7.9};
    vector<Complex> complex_v = {Complex(3, 5), Complex(7, -7), Complex(-1, 2)};

    cout << "Вектор целых чисел:\n";
    for(const auto& el : int_v) {
        cout << el << " ";
    }
    cout << endl << "Среднее арифметическое: "
         << arithm_mean(int_v) << endl;

    cout << "\nВектор чисел с плавающей точкой:\n";
    for(const auto& el : double_v) {
        cout << el << " ";
    }
    cout << endl << "Среднее арифметическое: "
         << arithm_mean(double_v) << endl;

    cout << "\nВектор комплексных чисел:\n";
    for(const auto& el : complex_v) {
        cout << el << " ";
    }
    cout << endl << "Среднее арифметическое: "
         << arithm_mean(complex_v) << endl;
    cout << endl;

    return 0;
}
