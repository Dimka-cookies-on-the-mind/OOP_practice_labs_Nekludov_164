
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
public:
    string name;
    int grade;

    Student (string n = " ", int g = 0) : name (n), grade (g) {}

    bool operator == (Student const& other) const {
        return name == other.name;
    }

    bool operator > (Student const& other) const {
        return grade > other.grade;
    }

    bool operator <= (Student const& other) const {
        return grade <= other.grade;
    }
    bool operator < (Student const& other) const {
        return grade < other.grade;
    }
    friend ostream& operator << (ostream& os, const Student& s)
    {
        os << s.name << " (" << s.grade << ") ";
        return os;
    }
};

int main()
{
    vector <Student> students = {{"Alice", 85}, {"Bob", 90}, {"Charline", 78}};

    cout << "Befor sort:" << endl;
    for(const auto& s : students) {
        cout << s;
    }
    cout << endl;

    sort(students.begin(), students.end());
    cout << "After:" << endl;
    for(const auto& s : students) {
        cout << s;
    }
    cout << endl;

    return 0;
}
