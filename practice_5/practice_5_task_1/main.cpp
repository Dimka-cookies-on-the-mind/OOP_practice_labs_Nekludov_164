#include <iostream>
#include <vector>

using namespace std;

class Shape {
protected:
    string name;
    string color;

public:
    Shape (string nm, string col) : name (nm), color (col) {}

    virtual double area () const = 0;
    virtual void draw () const = 0;

    bool operator == (Shape const& other) const {
        return (name == other.name)&&(color == other.color);
    }

    friend ostream& operator << (ostream& outs, const Shape& figura) {
        outs << figura.name << ", цвет " << figura.color;
        return outs;
    }

    virtual ~Shape() = default;
};

class Circle : public Shape {
private:
    float radius;

public:
    Circle (float r = 1, string col = "красный") : Shape ("Круг", col), radius (r) {}

    double area () const override {
        return radius * radius * 3.14;
    }

    void draw () const override {
        cout << "    ooo   " << endl << "  o     o " << endl
             << " o       o " << endl << "  o     o " << endl
             << "    ooo   " << endl;
    }

    Circle operator + (Circle const& cr2) const {
        return Circle (radius + cr2.radius, color);
    }
};

class Rectangle : public Shape {
private:
    float width;
    float height;

public:
    Rectangle (float w = 1, float h = 1, string col = "красный") :
        Shape ("Прямоугольник", col), width (w), height (h) {}

    double area () const override {
        return width * height;
    }

    void draw () const override {
        cout << " _____" << endl << "|     |" << endl << "|_____|" << endl;
    }
};

void printInfo (const Shape& shape) {
    cout << "Инфо о фигуре: " << shape << ", площадь: " << shape.area () << endl;
}

void printInfo (const Shape& shape, int detailLevel) {
    if (detailLevel > 0) {
        cout << "Детальное инфо: ";
        printInfo (shape);
        shape.draw ();
    }
}

int main ()
{
    vector<Shape*> shapes = { new Circle(5.0), new Rectangle(3.0, 4.0), new Circle(2.0, "зелёный") };
    for (auto shape : shapes) {
        printInfo(*shape);
        printInfo(*shape, 1);
        cout << endl;
    }

    Circle c1 (2, "голуой"), c2 (3, "фиолетовый");
    Circle c3 = c1 + c2;
    cout << "Сложили " << c1 << " (r = " << c1.area () << ") и "
         << c2 << " (r = " << c2.area () << ") : " << endl;
    printInfo (c3);
    for (auto shape : shapes)
        delete shape;

    return 0;
}
