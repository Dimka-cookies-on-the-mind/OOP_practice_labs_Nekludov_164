

#include <iostream>

using namespace std;

class Numbers {
private:
    int m_a;
    int m_b;
    int m_c;
    int m_d;

public:
    Numbers(int a, int b, int c, int d) {
        if(a >= 0 && a <= 9) {
            m_a = a;
        }
        else {
            m_a = 0;
        }
        if(b >= 0 && b <= 9) {
            m_b = b;
        }
        else {
            m_b = 0;
        }
        if(c >= 0 && c <= 9) {
            m_c = c;
        }
        else {
            m_c = 0;
        }
        if(d >= 0 && d <= 9) {
            m_d = d;
        }
        else {
            m_d = 0;
        }
    }

    Numbers(int abcd) {
        if(abcd <= 9999){
            m_d = abcd % 10;
            m_c = (abcd / 10) % 10;
            m_b = (abcd / 100) % 10;
            m_a = abcd / 1000;
        }
        else{
            m_a = 0;
            m_b = 0;
            m_c = 0;
            m_d = 0;
        }
    }

    int arithm_mean() {
        return (m_a + m_b + m_c + m_d) / 4;
    }

    int max_dig() {
        int max = m_a;
        if(max < m_b) {
            max = m_b;
        }
        if(max < m_c) {
            max = m_c;
        }
        if(max < m_d) {
            max = m_d;
        }
        return max;
    }

    void read_1_by_1() {
        int a, b, c, d;
        cout << "Input 4 digits: " << endl << " [a]: ";
        cin >> a;
        if(a >= 0 && a <= 9) {
            m_a = a;
        }
        else {
            m_a = 0;
        }
        cout << " [b]: ";
        cin >> b;
        if(b >= 0 && b <= 9) {
            m_b = b;
        }
        else {
            m_b = 0;
        }
        cout << " [c]: ";
        cin >> c;
        if(c >= 0 && c <= 9) {
            m_c = c;
        }
        else {
            m_c = 0;
        }
        cout << " [d]: ";
        cin >> d;
        if(d >= 0 && d <= 9) {
            m_d = d;
        }
        else {
            m_d = 0;
        }
    }

    void read_4_at_1() {
        int abcd;
        cout << "Input one 4-digital number: ";
        cin >> abcd;
        if(abcd <= 9999){
            m_d = abcd % 10;
            m_c = (abcd / 10) % 10;
            m_b = (abcd / 100) % 10;
            m_a = abcd / 1000;
        }
        else{
            m_a = 0;
            m_b = 0;
            m_c = 0;
            m_d = 0;
        }
    }

    void display() {
        cout << "This Number has next digits:" << endl << " a = " << m_a << endl << " b = " << m_b
             << endl << " c = " << m_c << endl << " d = " << m_d << endl << "And they have next parameters:"
             << endl << " arithmetic mean = " << arithm_mean() << endl << " max digit = " << max_dig() << endl;
    }

};

int main()
{
    Numbers n0 (0000);
    Numbers n0000 (0000);
    Numbers n1 (4, 2, 6, 9);
    Numbers n2 (7586);

    n0.read_1_by_1();
    n0000.read_4_at_1();

    cout << "Number 0" << endl;
    n0.display();
    cout << "Number 0.5" << endl;
    n0000.display();
    cout << "Number 1" << endl;
    n1.display();
    cout << "Number 2" << endl;
    n2.display();

    return 0;
}
