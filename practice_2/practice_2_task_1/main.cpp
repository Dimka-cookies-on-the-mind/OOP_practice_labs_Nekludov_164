#include <iostream>

using namespace std;

#define kol_vo 8
class Shape {
    int m_x, m_y;
public:
    Shape(int x, int y) : m_x(x), m_y(y) {}
    virtual void draw()const = 0;
    void move(int new_x, int new_y) {
        cout << "Previous position (" << m_x << " , " << m_y << ")" << endl
             << "New position (" << new_x << " , " << new_y << ")" << endl;
        m_x = new_x;
        m_y = new_y;
    }
    int get_x()const {
        return m_x;
    }
    int get_y()const {
        return m_y;
    }
};

class Rectangle : public Shape {
    int h, l;
public:
    Rectangle(int x, int y, int height, int lenght) : Shape(x, y), h(height), l(lenght) {}
    virtual void draw()const {
        cout << "The rectangle has these vertices: (" << get_x() << " , " << get_y() << ") ("
             << get_x() << " , " << get_y() + h << ") (" << get_x() + l << " , " << get_y() + h
             << ") (" << get_x() + l << " , " << get_y() << ")" << endl;
    }
};

class Circle : public Shape {
    int r;
public:
    Circle(int x, int y, int radius) : Shape(x, y), r(radius) {}
    virtual void draw()const {
        cout << "The circle is at (" << get_x() << " , " << get_y() << ") and has radius " << r
             << endl;
    }
};

int main()
{
    Shape* figuri[kol_vo];
    for(int i = 0; i < kol_vo; i++) {
        if(i % 2 == 0)
            figuri[i] = new Rectangle(2, 2 * i - 2, 2 * i, 3);
        else
            figuri[i] = new Circle(2 * i - 3, 1, 2 * i);
    }
    for(int i = 0; i < kol_vo; i++) {
        if(i % 2 == 0)
            cout << "Rectangle " << i / 2 + 1 << endl;
        else
            cout << "Circle " << (i + 1) / 2 << endl;
        figuri[i]->move(figuri[i]->get_x() + i, figuri[i]->get_y());
        figuri[i]->draw();
    }
    return 0;
}
