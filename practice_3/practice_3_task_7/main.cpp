#include <iostream>
using namespace std;

class GameCharacter {
private:
    string name;
    int health;
    int level;

public:
    GameCharacter(const string& charName, int initialHealth = 100, int initialLevel = 1)
        : name(charName), health(initialHealth), level(initialLevel) {}

    // Геттеры
    string getName() const { return name; }
    int getHealth() const { return health; }
    int getLevel() const { return level; }

    // Методы изменения характеристик
    void takeDamage(int damage) {
        if (damage > 0) {
            health -= damage;
            if (health < 0) health = 0;
            cout << name << " получил " << damage << " урона. Здоровье: " << health << "\n";
        }
    }

    void heal(int healAmount) {
        if (healAmount > 0) {
            health += healAmount;
            cout << name << " восстановил " << healAmount << " здоровья. Здоровье: " << health << "\n";
        }
    }

    void levelUp() {
        level++;
        health += 20; // Прибавка здоровья при повышении уровня
        cout << name << " повысил уровень до " << level << ". Здоровье увеличено до " << health << "\n";
    }
};

int main() {
    GameCharacter hero("Герой");
    cout << hero.getName() << ", уровень: " << hero.getLevel() << ", здоровье: " << hero.getHealth() << "\n";

    hero.takeDamage(30);
    hero.heal(15);
    hero.levelUp();

    return 0;
}
