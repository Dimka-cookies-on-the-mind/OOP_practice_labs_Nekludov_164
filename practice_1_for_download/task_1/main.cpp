
//Напишите программу, которая проверяет, является ли введённое число чётным или нечётным. Используйте оператор %.

#include <iostream>

using namespace std;

int main()
{
    cout << "Input some integer: ";
    int inp;
    cin >> inp;
    if(inp % 2 == 0)
        cout << "It was an even number." << endl;
    else
        cout << "It was an odd number." << endl;
    return 0;
}
