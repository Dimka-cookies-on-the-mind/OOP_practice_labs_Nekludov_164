#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string full_name_;
    int age_;
public:
    Person (const string& full_name, int age) :
        full_name_ (full_name), age_ (age) {}

    string get_full_name () const {
        return full_name_;
    }

    int get_age () const {
        return age_;
    }

    void who_are_you () const {
        cout << "ФИО: " << full_name_ << ", " << age_
             << " лет" << endl;
    }
};

class Employee : public Person {
private:
    string company_, position_;
public:
    Employee (const string& full_name, int age, const string& company, const string& position):
        Person (full_name, age), company_ (company), position_ (position) {}

    void who_are_you () const {
        Person::who_are_you ();
        cout << "Рабочий" << endl;
        cout << "Компания: " << company_ << ", должнось: " << position_ << endl;
    }
};

class Student : public Person {
private:
    string education_place_;
    int year_;
public:
    Student (const string& full_name, int age, const string& education_place, int year) :
        Person (full_name, age), education_place_ (education_place), year_ (year) {}

    void who_are_you () const {
        Person::who_are_you ();
        cout << "Место учёбы: " << education_place_ << ", курс: " << year_ << endl;
    }
};

int main()
{
    Person chelovek ("Иванов И. И.", 43);
    Employee rabotnek ("Егоров Е. Е.", 31, "Ростелеком", "Программист");
    Student student1 ("Петров П. П.", 20, "ТУСУР", 2);

    cout << "В главных ролях (программы)" << endl << endl;
    chelovek.who_are_you ();
    cout << endl;
    rabotnek.who_are_you ();
    cout << endl;
    student1.who_are_you ();
    cout << endl;

    return 0;
}
