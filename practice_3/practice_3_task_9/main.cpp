#include <iostream>
#include <string>
using namespace std;

class Human {
protected:
    string name;
    int age;

public:
    Human(const string& personName, int personAge)
        : name(personName), age(personAge) {}

    string getName() const { return name; }
    int getAge() const { return age; }
    void setName(const string& newName) { name = newName; }
    void setAge(int newAge) { age = newAge; }

    virtual void displayInfo() const {
        cout << "Имя: " << name << ", возраст: " << age << "\n";
    }
};

class Employee : public Human {
private:
    string position;

public:
    Employee(const string& empName, int empAge, const string& empPosition)
        : Human(empName, empAge), position(empPosition) {}

    string getPosition() const { return position; }
    void setPosition(const string& newPosition) { position = newPosition; }

    void displayInfo() const override {
        Human::displayInfo();
        cout << "Должность: " << position << "\n";
    }
};

int main() {
    Human person("Иван", 30);
    person.displayInfo();
    cout << endl;

    Employee employee("Мария", 28, "Разработчик");
    employee.displayInfo();
    employee.setPosition("Старший разработчик");
    cout << "Новая должность: " << employee.getPosition() << "\n";

    return 0;
}
