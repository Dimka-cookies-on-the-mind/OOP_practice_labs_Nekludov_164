#include <iostream>
#include <string>

using namespace std;


class Vehicle {
protected:
    string type_;
    int speed_;
    int wheelsCount_;
public:
    Vehicle(const string& type, int speed, int wheelsCount) : type_(type),
        speed_(speed), wheelsCount_(wheelsCount) {}

    void showInfo() const {
        cout << "Тип: " << type_ << endl
             << "Максимальная корость: " << speed_ << " км/ч\n"
             << "Кол-во колёс: " << wheelsCount_ << endl;
    }
};

class Car : public Vehicle {
private:
    int seats_;
public:
    Car(const string& type, int speed, int wheelsCount, int seats) :
        Vehicle(type, speed, wheelsCount), seats_(seats) {}

    void detailedInfo() const {
        showInfo();
        cout << "Количество сидячих мест: " << seats_ << endl;
    }
};

class Bike : public Vehicle {
private:
    bool hasPedals_;
public:
    Bike(const std::string& type, int speed, int wheelsCount, bool pedals)
        : Vehicle(type, speed, wheelsCount), hasPedals_(pedals) {}

    void detailedInfo() const {
        showInfo();
        cout << "Имеются педали: " << (hasPedals_ ? "Да" : "Нет") << "\n";  //Вау! Круто
    }
};

int main() {
    Car car("Tesla Model S", 250, 4, 5);
    cout << "Детали автомобиля:\n";
    car.detailedInfo();
    cout << "\n\n";

    Bike bike("Mountain Bike", 30, 2, true);
    cout << "Детали велосипеда:\n";
    bike.detailedInfo();
    cout << endl;
    return 0;
}
