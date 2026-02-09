//практика 2 задание 2

#include <iostream>

using namespace std;

class Shape {
    int m_x, m_y;
public:
    Shape(int x, int y) : m_x(x), m_y(y) {
        cout << "Shape constructor" << endl;
    }
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
    /*
    ~Shape() {
        cout << "Shape destructor" << endl;
    }
    так он не выводил "Rectangle destructor"
    */
    virtual ~Shape() {
        cout << "Shape destructor" << endl;
    } //а так выводит все 4 сообщения
};

class Rectangle : public Shape {
    int h, l;
public:
    Rectangle(int x, int y, int height, int lenght) : Shape(x, y), h(height), l(lenght) {
        cout << "Rectangle constructor" << endl;
    }
    virtual void draw()const {
        cout << "The rectangle has these vertices: (" << get_x() << " , " << get_y() << ") ("
             << get_x() << " , " << get_y() + h << ") (" << get_x() + l << " , " << get_y() + h
             << ") (" << get_x() + l << " , " << get_y() << ")" << endl;
    }
    ~Rectangle() {
        cout << "Rectangle destructor" << endl;
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
    Shape* figurka_ptr = new Rectangle(2, 3, 4, 7);
    delete figurka_ptr;
    return 0;
}
