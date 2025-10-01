
//Напишите программу, которая находит максимальный элемент массива, используя указатели и цикл.

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#define ar_min -10
#define ar_max 10

using namespace std;

int main()
{
    int ar_size;

    do{
        cout << "Сколько чисел сгенерировать (они будет лежать в диапазоне от " << ar_min << " до " << ar_max << "): ";
        cin >> ar_size;
    }while(ar_size <=0);

    int* A = new int[ar_size];

    srand(time(0));

    cout << "Случайные числа: ";
    for(int i = 0; i < ar_size; i++){
        if(i % 5 == 0)
            cout << endl;
        A[i] = (rand() % 21) - 10;
        cout << setw(4) << A[i];
    }
    cout << endl;

    int *maxA = &A[0];
    for(int i = 1; i < ar_size; i++){
        if(A[i] > *maxA)
            *maxA = A[i];

    }
    cout << "Максимальный элемент получился: " << *maxA << endl;

    delete[] A;
    return 0;
}
