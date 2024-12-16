#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <stdexcept>
#include <memory>
#include <map>
#include <set>
#include <functional>

using namespace std;

// Struct for name and surname
struct Name {
    string firstName;
    string surname;

    string getFullName() const {
        return firstName + " " + surname;
    }
};

// Character base class, assigned before spell to avoid errors
class Character {
protected:
    string name;
    int health;
    int attackPower;

public:
    Character(const Name &name, int health, int attackPower)
        : name(name.getFullName()), health(health), attackPower(attackPower) {
    } // Constructor for human
    Character(const string &name, int health, int attackPower)
        : name(name), health(health), attackPower(attackPower) {
    } // Constructor for monster

    virtual void attack(Character &opponent) = 0;

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0) health = 0;
    }

    void restoreHealth(int amount) {
        health += amount;
        cout << name << " восстанавливает здоровье до " << health << "!" << endl;
    }

    bool isAlive() const {
        return health > 0;
    }

    const string &getName() const {
        return name;
    }

    int getHealth() const {
        return health;
    }

    virtual ~Character() {
    }
};

// Spell base class
class Spell {
public:
    virtual void cast(Character &caster, Character &target) const = 0;

    virtual ~Spell() {
    }
};

// Spells
class Fireball : public Spell {
    int damage;

public:
    Fireball(int dmg) : damage(dmg) {
    }


    void cast(Character &caster, Character &target) const override {
        cout << "Casting Fireball spell. Caster: " << caster.getName() << ", Target: " << target.getName() << endl;
        // Debugging, don't work
        target.takeDamage(damage);
        cout << "Огненный шар наносит " << damage << " урона " << target.getName() << "!" << endl;
    } // Deal damage
};

class Heal : public Spell {
    int healAmount;

public:
    Heal(int heal) : healAmount(heal) {
    }

    void cast(Character &caster, Character &target) const override {
        caster.restoreHealth(healAmount);
        cout << "Заклинание исцеления восстанавливает " << healAmount << " здоровья " << caster.getName() << "!" <<
                endl;
    } // Healing
};

// Spells linker
class SpellGroup {
    string groupName;
    set<Spell *> spells; // Set of spells for not repeating

public:
    SpellGroup(const string &name) : groupName(name) {
    }

    void addSpell(Spell *spell) {
        if (!spells.insert(spell).second) {
            throw runtime_error("Заклинание уже есть в группе " + groupName);
        }
    }


    void castSpells(Character &caster, Character &target) const {
        for (const auto &spell: spells) {
            cout << "Применяем заклинание" << endl;
            spell->cast(caster, target); // Debugging
            cout << "Закончили применять заклинание" << endl;
        }
    }

    // Just cast all spells, should think about casting with keyboard

    ~SpellGroup() {
        for (auto &spell: spells) {
            delete spell;
        }
    }
};

// Just a spell book
class SpellBook {
    map<string, SpellGroup> groups;

public:
    void addGroup(const string &groupName) {
        if (groups.find(groupName) != groups.end()) {
            throw runtime_error("Группа " + groupName + " уже существует");
        }
        groups.emplace(groupName, SpellGroup(groupName));
    }

    void addSpellToGroup(const string &groupName, Spell *spell) {
        auto it = groups.find(groupName);
        if (it == groups.end()) {
            throw runtime_error("Группа " + groupName + " не существует");
        }
        it->second.addSpell(spell);
    }

    void castAllSpells(Character &caster, Character &target) const {
        for (const auto &pair: groups) {
            pair.second.castSpells(caster, target);
        }
    }
};


// Mage class
class Mage : public Character {
    SpellBook spellBook;

public:
    Mage(const Name &name, int health, int attackPower, const SpellBook &spellBook)
        : Character(name, health, attackPower), spellBook(spellBook) {
    }

    void attack(Character &opponent) override {
        cout << name << " использует заклинания!" << endl; // Debugging
        try {
            spellBook.castAllSpells(*this, opponent);
        } catch (const exception &e) {
            cerr << "Ошибка при использовании заклинания: " << e.what() << endl;
        }
    }
};

// Warrior class
class Warrior : public Character {
    Name fullName;

public:
    Warrior(const Name &name, int health, int attackPower)
        : Character(name, health, attackPower) {
    }

    void attack(Character &opponent) override {
        cout << fullName.getFullName() << " наносит удар!" << endl;
        opponent.takeDamage(attackPower);
    }
};

// Monster class
class Monster : public Character {
public:
    Monster(const string &name, int health, int attackPower)
        : Character(name, health, attackPower) {
    }

    void attack(Character &opponent) override {
        cout << name << " атакует!" << endl;
        opponent.takeDamage(attackPower);
    }
};

// Duel
void duel(Character &c1, Character &c2) {
    cout << "Дуэль между " << c1.getName() << " и " << c2.getName() << " началась!" << endl;
    while (c1.isAlive() && c2.isAlive()) {
        c1.attack(c2);
        if (c2.isAlive()) {
            c2.attack(c1);
        }
    }

    if (c1.isAlive()) {
        cout << c1.getName() << " победил!" << endl;
    } else {
        cout << c2.getName() << " победил!" << endl;
    }
}

// Battle function
void battle(Character *army1[], Character *army2[], int &size1, int &size2) {
    int i = 0, j = 0;

    while (i < size1 && j < size2) {
        duel(*army1[i], *army2[j]);
        if (army1[i]->isAlive()) {
            delete army2[j];
            army2[j] = nullptr;
            ++j;
        } else {
            delete army1[i];
            army1[i] = nullptr;
            ++i;
        }
    }

    if (i < size1) {
        cout << "Армия 1 победила! Выжившие:" << endl;
        for (int k = i; k < size1; ++k) {
            if (army1[k]) {
                cout << army1[k]->getName() << " (Здоровье: " << army1[k]->getHealth() << ")" << endl;
            }
        }
    } else {
        cout << "Армия 2 победила! Выжившие:" << endl;
        for (int k = j; k < size2; ++k) {
            if (army2[k]) {
                cout << army2[k]->getName() << " (Здоровье: " << army2[k]->getHealth() << ")" << endl;
            }
        }
    }
}


// Reading armies
void loadArmy(const string &filename, Character *army[], int &size) {
    ifstream file(filename);
    if (!file.is_open()) {
        throw runtime_error("Не удалось открыть файл: " + filename);
    }

    cout << "Открытие файла: " << filename << endl; // Debug

    string line;
    size = 0;
    while (getline(file, line)) {
        if (size >= 5) {
            throw runtime_error("Превышен максимальный размер армии");
        }

        string type;
        int health, attackPower;

        size_t firstSemicolon = line.find(';');
        type = line.substr(0, firstSemicolon);
        string data = line.substr(firstSemicolon + 1);

        size_t secondSemicolon, thirdSemicolon, fourthSemicolon;

        if (type == "Mage" || type == "Warrior") {
            secondSemicolon = data.find(';');
            string firstName = data.substr(0, secondSemicolon);
            data = data.substr(secondSemicolon + 1);

            thirdSemicolon = data.find(';');
            string surname = data.substr(0, thirdSemicolon);
            data = data.substr(thirdSemicolon + 1);

            fourthSemicolon = data.find(';');
            health = stoi(data.substr(0, fourthSemicolon)); // with stoi convert str to int
            attackPower = stoi(data.substr(fourthSemicolon + 1));

            Name charName = {firstName, surname};

            if (type == "Mage") {
                SpellBook book;
                book.addGroup("Основные");
                book.addSpellToGroup("Основные", new Fireball(50));
                book.addSpellToGroup("Основные", new Heal(30));
                army[size++] = new Mage(charName, health, attackPower, book);
                cout << "Добавлен маг: " << charName.getFullName() << " с " << health << " здоровья и " << attackPower
                        << " силы атаки." << endl; //code debugging, get std::bad_alloc error
            } else if (type == "Warrior") {
                army[size++] = new Warrior(charName, health, attackPower);
                cout << "Добавлен воин: " << charName.getFullName() << " с " << health << " здоровья и " << attackPower
                        << " силы атаки." << endl;
            }
        } else if (type == "Monster") {
            secondSemicolon = data.find(';');
            string name = data.substr(0, secondSemicolon);
            data = data.substr(secondSemicolon + 1);

            thirdSemicolon = data.find(';');
            health = stoi(data.substr(0, thirdSemicolon));
            attackPower = stoi(data.substr(thirdSemicolon + 1));

            army[size++] = new Monster(name, health, attackPower);
            cout << "Добавлен монстр: " << name << " с " << health << " здоровья и " << attackPower << " силы атаки." <<
                    endl; // Debug
        } else {
            throw runtime_error("Неизвестный тип персонажа: " + type);
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    try {
        Character *army1[5];
        Character *army2[5];
        int size2;
        int size1;
        loadArmy("D:/MIPT/cpp3sem/Project/army1.txt", army1, size1); // Insert YOUR filepath
        loadArmy("D:/MIPT/cpp3sem/Project/army2.txt", army2, size2); // Insert YOUR filepath

        battle(army1, army2, size1, size2);


        // Clearing memory
        for (int i = 0; i < size1; ++i) {
            delete army1[i];
            army1[i] = nullptr;
        }
        for (int i = 0; i < size2; ++i) {
            delete army2[i];
            army2[i] = nullptr;
        }
    } catch (const exception &e) {
        cerr << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
