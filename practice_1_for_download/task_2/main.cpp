
//Напишите программу, которая запрашивает у пользователя два целых числа и меняет их местами с помощью указателей.

#include <iostream>

using namespace std;

int main()
{
    int inp1, inp2;
    cout << "Input same integer: ";
    cin >> inp1;
    cout << "Input one more integer: ";
    cin >> inp2;
    cout << "Before changes: " << inp1 << "  " << inp2 << endl;
    int *ptr1 = &inp1;
    int *ptr2 = &inp2;
    int buff = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = buff;
    cout << "After changes: " << inp1 << "  " << inp2 << endl;

    return 0;
}
