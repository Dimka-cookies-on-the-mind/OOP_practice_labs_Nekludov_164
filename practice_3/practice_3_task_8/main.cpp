#include <iostream>
#include <string>
using namespace std;

struct Point {
    double x;
    double y;

    Point(double xCoord = 0.0, double yCoord = 0.0) : x(xCoord), y(yCoord) {}

    void print() const {
        cout << "Точка (" << x << ", " << y << ")\n";
    }
};

class ColoredPoint : public Point {
private:
    string color;

public:
    ColoredPoint(double xCoord, double yCoord, const string& col)
        : Point(xCoord, yCoord), color(col) {}

    string getColor() const { return color; }
    void setColor(const string& newColor) { color = newColor; }

    void print() const {
        Point::print();
        cout << "Цвет: " << color << "\n";
    }
};

int main() {
    Point p(1.5, 2.5);
    p.print();
    cout << endl;

    ColoredPoint cp(3.0, 4.0, "красный");
    cp.print();

    cp.setColor("синий");
    cout << "Новый цвет: " << cp.getColor() << "\n";

    return 0;
}
