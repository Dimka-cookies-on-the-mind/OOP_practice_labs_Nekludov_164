#include <iostream>

using namespace std;

struct Point {
    int X;
    int Y;
};

struct RGBColor {
    unsigned char Red;
    unsigned char Green;
    unsigned char Blue;
};

class ColoredPoint : public Point {
public:
    RGBColor Color;
};

int main()
{
    ColoredPoint A;
    A.X = 10;
    A.Y = 20;
    A.Color.Red = 100;
    A.Color.Green = 150;
    A.Color.Blue = 10;
    cout << "Привет, мир! У меня есть точка A!" << endl;
    cout << "Её координаты {" << A.X << " " << A.Y << "}" << endl <<
        "Её цвет по RGB модели {" << +A.Color.Red << " " << +A.Color.Green << " " << +A.Color.Blue <<
        "}" << endl;
    return 0;
}
