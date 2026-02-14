#include <iostream>

using namespace std;

class Vector2D {
private:
    double m_x;
    double m_y;
public:
    Vector2D(double x = 0, double y = 0) : m_x(x), m_y(y) {}

    Vector2D operator + (const Vector2D& other) const {
        return Vector2D(m_x + other.m_x, m_y + other.m_y);
    }

    Vector2D operator - (const Vector2D& other) const {
        return Vector2D(m_x - other.m_x, m_y - other.m_y);
    }

    Vector2D operator * (const Vector2D& other) const {
        return m_x * other.m_x + m_y * other.m_y;
    }

    Vector2D operator * (double& n) const {
        return Vector2D(m_x * n, m_y * n);
    }

    double operator [] (int index) const {
        if (index == 0)
            return m_x;
        else if (index == 1)
            return m_y;
        else
            return 0;
    }

    friend ostream& operator << (ostream& os, const Vector2D v) {
        os << "(" << v.m_x << ", " << v.m_y << ")";
        return os;
    }
};

int main()
{
    Vector2D v1(3, 7);
    Vector2D v2(2, 1);
    cout << "v1 = " << v1 << endl;
    cout << "v2 = " << v2 << endl;
    cout << "v1 + v2 = " << v1 + v2 << endl;
    cout << "v1 - v2 = " << v1 - v2 << endl;
    cout << "v1 * v2 (scal) = " << v1 * v2 << endl;
    cout << "v1 * 2.5 = " << v1 * 2.5 << endl;
    cout << "v1[0] = " << v1[0] << ", v1[1] = " << v1[1] << endl;
    return 0;
}
