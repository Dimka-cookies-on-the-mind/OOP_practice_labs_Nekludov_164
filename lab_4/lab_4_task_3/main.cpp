#include <iostream>

using namespace std;

template <class T>
class Vector {
private:
    T _x0, _y0, _z0;
public:
    Vector(T x0, T y0, T z0) :
        _x0(x0), _y0(y0), _z0(z0) {}

    void read() {
        cout << "Введите длины вектора по осям:\n";
        cout << "x = "; cin >> _x0;
        cout << "y = "; cin >> _y0;
        cout << "z = "; cin >> _z0;
    }

    void display() const {
        cout << "(" << _x0 << ", " << _y0 << ", " << _z0 << ")\n";
    }

    friend ostream& operator << (ostream& outs, Vector const& vec) {
        outs << "(" << vec._x0 << ", " << vec._y0 << ", " << vec._z0 << ")";
        return outs;
    }

    Vector operator + (Vector const& other) const {
        return Vector(_x0 + other._x0, _y0 + other._y0, _z0 + other._z0);
    }

    Vector operator - (Vector const& other) const {
        return Vector(_x0 - other._x0, _y0 - other._y0, _z0 - other._z0);
    }

    Vector operator * (T const& operand) const {
        return Vector(_x0 * operand, _y0 * operand, _z0 * operand);
    }

    T scalar_product(Vector const& other) const {
        return _x0 * other._x0 + _y0 * other._y0 + _z0 * other._z0;
    }

    Vector vector_product(Vector const& other) const {
        return Vector(
            _y0 * other._z0 - _z0 * other._y0,
            _z0 * other._x0 - _x0 * other._z0,
            _x0 * other._y0 - _y0 * other._x0);
    }
};

int main()
{
    Vector<int> integer_v(3, 7, -5);
    Vector<double> real_v1(3.8, -3.4, 2.1);
    Vector<double> real_v2(-2.7, 3.9, 8.4);

    cout << "Имеемые вектора: \n";
    cout << "Целочисленный в.: ";
    integer_v.display();
    cout << "Вещественный в. первый: ";
    real_v1.display();
    cout << "Вещественный в. второй: ";
    real_v2.display();

    cout << "\nМатематические над ними операции: \n";
    cout << real_v1 << " + " << real_v2 << " = "
         << real_v1 + real_v2 << endl;
    cout << real_v1 << " - " << real_v2 << " = "
         << real_v1 - real_v2 << endl;
    cout << integer_v << " * 3 = "
         << integer_v * 3 << endl;
    cout << "( " << real_v1 << ", " << real_v2 << " ) = "
         << real_v1.scalar_product(real_v2) << endl;
    cout << "[ " << real_v1 << ", " << real_v2 << " ] = "
         << real_v1.vector_product(real_v2) << endl;

    return 0;
}
