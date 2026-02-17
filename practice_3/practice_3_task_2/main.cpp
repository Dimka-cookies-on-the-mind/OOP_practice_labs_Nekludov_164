#include <iostream>

using namespace std;

#define MAX_GRADES 5

class Student {
private:
    int grades[MAX_GRADES];
    int currentIndex;
public:
    Student() : currentIndex(0) {
        for (int i = 0; i < MAX_GRADES; ++i) {
            grades[i] = 0;
        }
    }

    void setGrade(int grade) {
        if (currentIndex < MAX_GRADES) {
            grades[currentIndex++] = grade;
        } else {
            cout << "Нельзя добавлять больше оценок. Максимум 5 оценок." << endl;
        }
    }

        double calculateAverage() const {
        if (currentIndex == 0) {
            return 0.0;
        }
        int sum = 0;
        for (int i = 0; i < currentIndex; ++i) {
            sum += grades[i];
        }
        return static_cast<double>(sum) /
               currentIndex;
    }
};
int main() {
    Student student;

    student.setGrade(4);
    student.setGrade(5);
    student.setGrade(3);
    student.setGrade(4);
    student.setGrade(5);

    cout << "Средний балл студента: "
         << student.calculateAverage() << endl;
    return 0;
}
