#include <iostream>

using namespace std;

class TriangleChecker {
private:
    float m_a_side;
    float m_b_side;
    float m_c_side;

public:
    bool is_isosceles() {
        return m_a_side == m_b_side || m_b_side == m_c_side || m_c_side == m_a_side;
    }

    void read() {
        cout << "Enter the triangle sides:" << endl << "The first: ";
        cin >> m_a_side;
        cout << "The second: ";
        cin >> m_b_side;
        cout << "The third: ";
        cin >> m_c_side;
    }

    void display() {
        cout << "This triangle has these sides lengths: " << m_a_side << ", " << m_b_side
             << ", " << m_c_side << endl << "So it is ";

        if(is_isosceles()) {
            cout << "isosceles";
        }
        else {
            cout << "not isosceles";
        }
        cout << endl;
    }
};

int main()
{
    TriangleChecker my_trig;

    my_trig.read();

    my_trig.display();

    return 0;
}
