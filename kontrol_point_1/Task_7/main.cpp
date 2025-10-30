#include <iostream>

using namespace std;

class CPersonage {
private:
    int Health;
    int Hunger;
public:
    void Hit () {
        Health -= 10;
    }
    void Eat () {
        Hunger -= 10;   //пусть нулвой голод - хорошо
        Health += 5;
    }
    void Run () {
        Hunger += 10;
    }
    int GetHealth () {
        return Health;
    }
    int GetHunger () {
        return Hunger;
    }
    void PrintStates () {
        cout << "Здоровье " << Health << ", голод " << Hunger << endl;
    }
    CPersonage () : Health (100), Hunger (0) {}
};

int main()
{
    CPersonage Player1;
    cout << "Жил-был персонаж Player1." << endl << "Здоровье у него было " << Player1.GetHealth() <<
        ", голода " << Player1.GetHunger() << endl <<
        "Захотелось ему побегать. Всё бы ничего, только есть захотелось немного." << endl;
    Player1.Run ();
    Player1.PrintStates ();
    cout << "Но его ударили!" << endl;
    Player1.Hit ();
    Player1.PrintStates();
    cout << "Он попытался восполнить здоровье и поел." << endl;
    Player1.Eat();
    Player1.PrintStates();
    return 0;
}
