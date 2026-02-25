#include <iostream>
#include <string>

using namespace std;

class Box {
private:
    int _lenght;
    int _width;
    int _height;
public:
    Box (int lenght, int width, int height) :
        _lenght (lenght), _width (width), _height (height) {}

    int get_l () const {
        return _lenght;
    }
    int get_w () const {
        return _width;
    }
    int get_h () const {
        return _height;
    }

    void read () {  //по заданию складывается такое впечатление,
        //что эту функцию делать не надо, но я не был уверен, простите
        cout << "Введите размеры коробки (в см): \n";
        cout << "Длина: "; cin >> _lenght;
        cout << "Ширина: "; cin >> _width;
        cout << "Высота: "; cin >> _height;
    }

    void display () const {
        cout << "Размеры коробки: \n";
        cout << "Длина: " << _lenght << " см" << endl;
        cout << "Ширина: " << _width << " см" << endl;
        cout << "Высота: " << _height << " см" << endl;
    }
};

class WrappingPaper {
private:
    string _color;
    float _price_cm_cm;
public:
    WrappingPaper (string color, float price_cm_cm) :
        _color (color), _price_cm_cm (price_cm_cm) {}

    string get_color () const {
        return _color;
    }
    float get_price_cm_cm () const {
        return _price_cm_cm;
    }

    void read () {
        cout << "Введите цвет упаковочной бумаги (словом): ";
        cin >> _color;
        cout << "Ввеидте цену одного квадратного сантиметра (в руб.): ";
        cin >> _price_cm_cm;
    }

    void display () const {
        cout << "Цвет упаковочной бумаги: " << _color << endl;
        cout << "Цена за один квадратный сантиметр: "
             << _price_cm_cm << " руб." << endl;
    }
};

class Present : private Box, private WrappingPaper {
public:
    Present (int lenght, int width, int height, string color, float price_cm_cm) :
        Box (lenght, width, height), WrappingPaper (color, price_cm_cm) {}

    float get_full_price_of_wrapping () const {
        return 2 * (get_l () * get_w () + get_w () * get_h () + get_h () * get_l ()) * get_price_cm_cm ();
    }

    void read () {
        cout << "Введите параметры подарка: \n";
        Box::read ();
        WrappingPaper:: read ();
    }

    void display () const {
        cout << "Подарок: \n";
        Box::display ();
        WrappingPaper::display ();
        cout << "Цена всей упаковочной бумаги этого подарка (впритык): "
             << get_full_price_of_wrapping () << " руб." << endl;
    }
};

int main()
{
    Present gift (10, 10, 7, "фиолетовый", 0.01);
    gift.display ();

    return 0;
}
