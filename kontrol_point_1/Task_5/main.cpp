#include <iostream>

using namespace std;

class Person {
public:
    string name;
    string surname;
    string patronymic;
    int age;
    Person (string n, string s, string p, int a) :
        name (n), surname (s), patronymic (p), age (a) {}
};

class Employee : public Person {
public:
    string profession;
    string place_of_work;
    Employee (string n, string s, string p, int a, string prof, string pl) :
        Person (n, s, p, a), profession (prof), place_of_work (pl) {}
};

class Student : public Person {
public:
    string specialization;
    string place_of_education;
    Student (string n, string s, string p, int a, string spec, string pl) :
        Person (n, s, p, a), specialization (spec), place_of_education (pl) {}
};

int main()
{
    Employee programer ("Иван ", "Иванов ", "Иванович ", 30, "Программист", "Где-то в Москве");
    Student st ("Павел ", "Павлов ", "Павлович ", 20 , "Радиотехник", "ТУСУР");

    cout << "Имеемый работник: " << endl << programer.surname << programer.name << programer.patronymic <<
        endl << "Возраст " << programer.age << endl << programer.profession << endl << "Место работы: " <<
        programer.place_of_work << endl;
    cout << endl;
    cout << "Имеемый студент: " << endl << st.surname << st.name << st.patronymic << endl <<
        "Возраст " << st.age << endl << st.specialization << endl << "Место учёбы: " << st.place_of_education;
    cout << endl;

    return 0;
}
