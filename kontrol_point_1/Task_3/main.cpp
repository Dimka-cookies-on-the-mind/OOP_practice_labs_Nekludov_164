
#include <iostream>

using namespace std;

class Vehicle {
protected:
    float speed = 0;
    float max_speed;
    string brand;
    string model;
public:
    float get_speed () const {
        return speed;
    }
    float get_max_speed () const {
        return max_speed;
    }
    string get_brand () const {
        return brand;
    }
    string get_model () const {
        return model;
    }
    void set_speed (float & new_speed) {
        if (new_speed <= max_speed) {
            speed = new_speed;
        }
        else {
            speed = max_speed;
        }
    }
    Vehicle (string Brand, string Model, float MaxSpeed_kmh):
        max_speed (MaxSpeed_kmh), brand (Brand), model (Model) {}
};
class Car: public Vehicle {
protected:
    int num_doors;
public:
    int get_num_doors() const {
        return num_doors;
    }
    void honk () const {
        cout << "\"Би-бип\"" << endl;
    }
    Car (string Brand, string Model, float MaxSpeed_kmh, int NumDoors):
        Vehicle(Brand, Model, MaxSpeed_kmh), num_doors (NumDoors) {}
};
class Bicycle: public Vehicle {
protected:
    int num_speed_modes;
public:
    int get_num_speed_modes () const {
        return num_speed_modes;
    }
    void bell () const {
        cout << "\"Дзынь-дзынь\"" << endl;
    }
    Bicycle (string Brand, string Model, float MaxSpeed_kmh, int NumSpeedModes):
        Vehicle (Brand, Model, MaxSpeed_kmh), num_speed_modes (NumSpeedModes) {}
};

int main()
{
    Vehicle some_vehivle ("Бренд_1", "Модель_1", 20);
    Car tachka ("Москвич", "Москвич 3", 200, 4);
    Bicycle velik ("Десна", "2910 MD 29 2019", 40, 21);
    float sp = 18;
    some_vehivle.set_speed(sp);
    cout << "Неизвестное транспортное средство: бренд " << some_vehivle.get_brand() <<
        ", модель " << some_vehivle.get_model() << endl << "Максимальная скорость " <<
        some_vehivle.get_max_speed() << endl << "Текущая скорость " << some_vehivle.get_speed() <<
        ". Задайте новую: ";
    cin >> sp;
    some_vehivle.set_speed(sp);
    cout << "Текущая скорость " << some_vehivle.get_speed() << endl;
    cout << "Машина: бренд " << tachka.get_brand() << ", модель " << tachka.get_model() << endl <<
        "Количество дверей " << tachka.get_num_doors() << ", максимальная скорость " <<
        tachka.get_max_speed() << endl << "Текущая скорость " << tachka.get_speed() << ". Задайте новую: ";
    cin >> sp;
    tachka.set_speed(sp);
    cout << "Текущая скорость " << tachka.get_speed() << endl;
    tachka.honk();
    cout << "Велосипед: бренд " << velik.get_brand() << ", модель " << velik.get_model() << endl <<
        "Количество скоростных режимов " << velik.get_num_speed_modes() <<
        ", максимальная скорость " << velik.get_max_speed() << endl << "Текущая скорость " <<
        velik.get_speed() << ". Задайте новую: ";
    cin >> sp;
    velik.set_speed(sp);
    cout << "Текущая скорость " << velik.get_speed() << endl;
    velik.bell();

    return 0;
}












