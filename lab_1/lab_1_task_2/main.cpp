
//вариант 2 (задачи 2, 8, 11, 16)

#include <iostream>

using namespace std;

class Product {
private:
    unsigned int m_price;
    unsigned int m_number;

public:
    unsigned int get_full_price() {
        return m_price * m_number;
    }

    void read() {
        cout << "Enter pruduct price: ";
        cin >> m_price;
        cout << "Enter product number: ";
        cin >> m_number;
    }

    void display() {
        cout << "Product price " << m_price << endl <<
                "Product number " << m_number << endl;
    }
};

int main()
{
    Product my_product;

    my_product.read();

    my_product.display();

    cout << "Full product price " << my_product.get_full_price() << endl;

    return 0;
}
