#include <iostream>

using namespace std;

class Human {
public:
    string Name;
    int Age;
};

class Employee : public Human {
public:
    string Proffesion;
};

int main()
{
    Human H;
    H.Name = "Петя";
    H.Age = 30;
    cout << "У нас есть просто человек: " << endl;
    cout << "Имя " << H.Name << ", возраст " << H.Age << endl;
    Employee E;
    E.Name = "Пётр";
    E.Age = 33;
    E.Proffesion = "Блинопекарь";
    cout << "А есть рабочий: " << endl;
    cout << "Имя " << E.Name << ", возраст " << E.Age << ", должность " << E.Proffesion <<
        endl;

    return 0;
}
