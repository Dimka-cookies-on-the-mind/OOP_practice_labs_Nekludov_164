


#include <iostream>

using namespace std;

class student{
private:
    //string name;
    int math_mark;
    int eng_mark;
    int prog_mark;
public:
    void set_math_mark (int new_math_mark) {
        math_mark = new_math_mark;
    }
    void set_eng_mark (int new_eng_mark) {
        eng_mark = new_eng_mark;
    }
    void set_prog_mark (int new_prog_mark) {
        prog_mark = new_prog_mark;
    }
    int get_mid_mark () {
        float mid_mark = (math_mark + eng_mark + prog_mark) / 3;
        return mid_mark;
    }
};

int main()
{
    string subj [] = {"Математика", "Английский", "Программирование"};
    string stud [] = {"Мишель", "Маша", "Кирилл"};
    student s [3];
    student Michel;
    student Masha;
    student Kirill;
    int searched_stud;
    int searched_subj;
    int mark;
    int j = 0;
    bool end = 0;

    while ((j < 12) && (end == 0)){
        cout << "Выберите студента: " << endl;
        for (int i = 0; i < 3; i++) cout << stud [i] << " - " << i + 1 << endl;
        do {
            cin >> searched_stud;
        } while (!((searched_stud < 4) && (searched_stud > 0)));
        cout << stud [searched_stud - 1] << endl << "Выберите предмет" << endl;
        for (int i = 0; i < 3; i++) cout << subj [i] << " - " << i + 1 << endl;
        do {
            cin >> searched_subj;
        } while (!((searched_subj < 4) && (searched_subj > 0)));
        cout << subj [searched_subj - 1] << ", оценка = ";
        do {
            cin >> mark;
        } while (!((mark < 6) && (mark > 0)));
        cout << "Закончить - 1, продолжить - 0: ";
        cin >> end;
        switch (searched_subj) {
        case 1 :
            s [searched_stud - 1].set_math_mark(mark);
            break;
        case 2 :
            s [searched_stud - 1].set_eng_mark(mark);
            break;
        case 3 :
            s [searched_stud - 1].set_prog_mark(mark);
        }
        j++;
    }
    cout << endl;
    for (int j = 0; j < 3; j++){
        cout << "Средняя оценка:" << endl;
        for (int i = 0; i < 3; i++) cout << stud [i] << " - " << i + 1 << endl;
        do {
            cin >> searched_stud;
        } while (!((searched_stud < 4) && (searched_stud > 0)));
        cout << "Значение: " << s [searched_stud - 1].get_mid_mark() << endl;
    }

    return 0;
}
