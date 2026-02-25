#include <iostream>

using namespace std;

class Parallelepiped {
protected:
    float _a;
    float _b;
    float _c;
public:
    Parallelepiped (float a = 1, float b = 1, float c = 1) :
        _a (a), _b (b), _c (c) {}

    float get_volume () const {
        return _a * _b * _c;
    }

    void read () {
        cout << "Введите длины сторон параллелепипеда: \n";
        cout << "a = "; cin >> _a;
        cout << "b = "; cin >> _b;
        cout << "c = "; cin >> _c;
    }

    void display () const {
        cout << "Длины сторон параллелепипеда: \n";
        cout << "a = " << _a << endl;
        cout << "b = " << _b << endl;
        cout << "c = " << _c << endl;
    }
};

class MetalBar : public Parallelepiped {
private:
    float _specific_gravity;
public:
    MetalBar (float specific_gravity = 7, float a = 1, float b = 1, float c = 1) :
        Parallelepiped (a, b, c), _specific_gravity (specific_gravity) {}

    float get_full_gravity () const {
        return get_volume () * _specific_gravity;
    }

    void read () {
        cout << "Введите удельный вес металла: \n";
        cout << "p = "; cin >> _specific_gravity;
        cout << "Введите длины сторон бруска: \n";
        cout << "a = "; cin >> _a;
        cout << "b = "; cin >> _b;
        cout << "c = "; cin >> _c;
    }

    void display () const {
        cout << "Удельный вес металла: \n";
        cout << "p = " << _specific_gravity << endl;
        cout << "Длины сторон бруска: \n";
        cout << "a = " << _a << endl;
        cout << "b = " << _b << endl;
        cout << "c = " << _c << endl;
        cout << "Вес бруска: " << get_full_gravity() << endl;
    }
};

int main()
{
    Parallelepiped parlep;
    MetalBar met_b;
    cout << "Введите параметры параллелепипеда: \n";
    parlep.read ();
    cout << "И металлического бруса: \n";
    met_b.read ();
    cout << "Информация о них: \n";
    parlep.display ();
    met_b.display ();

    return 0;
}
