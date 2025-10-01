
//Напишите программу, которая суммирует положительные элементы массива, использовав условные операторы и цикл.

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

    int counter = 0;
    int pos_sum = 0;
    while(counter < ar_size){
        if(A[counter] > 0){
            pos_sum += A[counter];
        }
        counter++;
    }
    cout << "Сумма положительных элементов в сгенерированном массиве: " << pos_sum << endl;

    delete[] A;

    return 0;
}
