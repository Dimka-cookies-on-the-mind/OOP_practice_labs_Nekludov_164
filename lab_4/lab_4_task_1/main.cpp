#include <iostream>

using namespace std;

template <class T, size_t rows, size_t cols>
bool is_there(const T (&A)[rows][cols], const T& elem) {
    for(size_t i = 0; i < rows; ++i) {
        for(size_t j = 0; j < cols; ++j) {
            if(A[i][j] == elem) {
                return true;
            }
        }
    }
    return false;
}

template <class T, size_t rows, size_t cols>
void read(T (&A)[rows][cols]) {
    cout << "Введите массив (" << rows << "*" << cols << "): " << endl;
    for(size_t i = 0; i < rows; ++i) {
        for(size_t j = 0; j < cols; ++j) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }
    }
}

template <class T, size_t rows, size_t cols>
void display(const T (&A)[rows][cols]) {
    for(size_t i = 0; i < rows; ++i) {
        for(size_t j = 0; j < cols; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int int_array[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    double double_array[4][3] = {
        {1.2, 2.3, 3.4},
        {4.5, 5.6, 6.7},
        {7.8, 8.9, 9.1},
        {10.11, 11.12, 12.13}
    };
    char char_array[2][3] = {
        {'a', 'b', 'c'},
        {'d', 'E', 'f'}
    };

    cout << "int_array: \n";
    display(int_array);
    cout << "\ndouble_array: \n";
    display(double_array);
    cout << "\nchar_array: \n";
    display(char_array);

    cout << "В int_array есть элемент 7: " << (is_there(int_array, 7) ? "да" : "нет") << endl;
    cout << "В double_array есть элемент 21.3: " << (is_there(double_array, 21.3) ? "да" : "нет") << endl;
    cout << "В char_array есть элемент z: " << (is_there(char_array, 'z') ? "да" : "нет") << endl;

    read(int_array);

    return 0;
}
