//практика 4, задание 5

#include <iostream>

using namespace std;

class Vector2D;
class Matrix2x2 {
private:
    double data[2][2];
public:
    Matrix2x2() {
        data[0][0] = data[0][1] = data[1][0] = data[1][1] = 0; }
    Matrix2x2(double a, double b, double c, double d) {
        data[0][0] = a;
        data[0][1] = b;
        data[1][0] = c;
        data[1][1] = d;
    }

    Matrix2x2 operator + (const Matrix2x2& other) const {
        Matrix2x2 result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix2x2 operator * (const Matrix2x2& other) const {
        Matrix2x2 result;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < 2; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Vector2D operator * (const Vector2D& vec) const;

    double& operator () (int row, int col) {
        if (row < 0 || row >= 2 || col < 0 || col >= 2) {
            throw out_of_range("Matrix indices must be 0 or 1");
        }
        return data[row][col];
    }

    friend ostream& operator << (ostream& os, const Matrix2x2& mat) {
        os << "/[" << mat.data[0][0] << ", " << mat.data[0][1] << "]\\" << endl
           << "\\[" << mat.data[1][0] << ", " << mat.data[1][1] << "]/";
        return os;
    }
};

class Vector2D {
private:
    double x, y;
public:
    Vector2D(double x_val = 0, double y_val = 0) : x(x_val), y(y_val) {}
    double getX() const { return x; }
    double getY() const { return y; }
    friend ostream& operator << (ostream& os, const Vector2D& vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }
};

Vector2D Matrix2x2::operator * (const Vector2D& vec) const {
    return Vector2D(data[0][0] * vec.getX() + data[0][1] * vec.getY(),
                    data[1][0] * vec.getX() + data[1][1] * vec.getY());
}

int main() {
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);
    cout << "Матрица m1:\n" << m1 << endl;
    cout << "\nМатрица m2:\n" << m2 << endl;

    Matrix2x2 sum = m1 + m2;
    cout << "\nm1 + m2:\n" << sum << endl;

    Matrix2x2 product = m1 * m2;
    cout << "\nm1 * m2:\n" << product << endl;

    Vector2D v(2, 3);
    Vector2D result = m1 * v;
    cout <<"\nv = " << v << endl;
    cout << "m1 * v" << " = " << result << endl;

    cout << "\nДоступ к элементам m1:" << endl;
    cout << "m1(0,0) = " << m1(0, 0) << endl;
    cout << "m1(1,1) = " << m1(1, 1) << endl;
    m1(0, 1) = 10; cout << "\nПосле m1(0,1) = 10:\n"
         << m1 << endl;
    return 0;
}
