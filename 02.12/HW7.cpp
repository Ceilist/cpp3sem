#include <functional>
#include <iostream>
#include <string>
#include <stdexcept>
#include <map>
#include <set>
#include <windows.h>

using namespace std;

// Абстрактный базовый класс для заклинаний
class Spell {
public:
    // Использование заклинания и виртуальный деструктор
    virtual void cast() const = 0;
    virtual void SpellName() const = 0;
    virtual ~Spell() {
    }
};

// Шаблон для классов
template<const char *TypeName>
class SpellType : public Spell {
    string name;

public:
    SpellType(const string &name) : name(name) {
    }

    void cast() const override {
        cout << "Применяем " << TypeName << " заклинание " << name << endl;
    }

    void SpellName() const override {
        cout << name << endl;
    }

    const string &getName() const {
        return name;
    }
};

// Определение типов заклинаний
const char atk[] = "Attack";
const char def[] = "Defensive";

// Создаем заклинания фабрикой
class SpellFactory {
    typedef map<string, function<Spell*(const string&)>> FactoryMap; // Храним типы заклинаний
    // Function нужна, чтобы корректно передавать указатель на класс
    FactoryMap creators;
    set<string> spellNames; // Для проверки уникальности имен

public:
    // Создаем типы
    template<const char *TypeName>
    void add(const string &key) {
        creators[key] = [](const string &name) -> Spell *{
            return new SpellType<TypeName>(name);
        };
    }

    // Создаем заклинания
    Spell *createSpell(const string &key, const string &name) {
        // Проверка уникальности
        if (spellNames.find(name) != spellNames.end()) {
            throw runtime_error("Заклинание \"" + name + "\" существует");
        }
        // Создаем новое заклинаний типа key
        auto it = creators.find(key);
        if (it != creators.end()) {
            Spell *newSpell = it->second(name);
            spellNames.insert(name); // Добавляем имя заклинания в множество
            return newSpell;
        }
        throw runtime_error("Нет типа заклинаний " + key);
    }

    // Удаление заклинания
    void deleteSpell(Spell *spell, const string &name) {
        auto it = spellNames.find(name);
        if (it != spellNames.end()) {
            spellNames.erase(it); // Удаляем имя из множества
            delete spell; // Удаляем объект
        }
    }
};

// Компоновщик для группировки заклинаний по типам
class SpellGroup {
    string groupName;
    set<Spell*> spells; // Уникальные заклинания

public:
    SpellGroup(const string &name) : groupName(name) {}
    // Добавляем заклинание
    void addSpell(Spell *spell) {
        if (!spells.insert(spell).second) {
            throw runtime_error("Заклинание уже есть в группе \"" + groupName + "\"");
        }
    }
    // Удаляем заклинание
    void removeSpell(Spell *spell) {
        if (spells.erase(spell) == 0) {
            throw runtime_error("Заклинание не существует в группе \"" + groupName + "\"");
        }
        delete spell;
    }
    // Используем все заклинания группы
    void castAll() const {
        cout << "Заклинания из группы \"" << groupName << "\": ";
        for (const auto &spell : spells) {
            spell->SpellName();
        }
    }
    //Название типа
    const string &getName() const {
        return groupName;
    }
    // Деструктор
    ~SpellGroup() {
        for (auto &spell : spells) {
            delete spell;
        }
    }
};

// Шаблон для книги заклинаний
template <typename SpellGroupType>
class SpellBook {
    map<string, SpellGroupType> groups; // Группы заклинаний по именам

public:
    // Добавление группы заклинаний
    void addGroup(const string &groupName) {
        if (groups.find(groupName) != groups.end()) {
            throw runtime_error("Группа \"" + groupName + "\" уже существует");
        }
        groups.emplace(groupName, SpellGroupType(groupName)); // Метод для добавления класса в сет
    }

    // Добавление заклинания в группу
    void addSpellToGroup(const string &groupName, Spell *spell) {
        auto it = groups.find(groupName);
        if (it == groups.end()) {
            throw runtime_error("Группа \"" + groupName + "\" не существует");
        }
        it->second.addSpell(spell);
    }

    // Применение всех заклинаний из всех групп
    void castAll() const {
        for (const auto &pair : groups) {
            pair.second.castAll(); // Обращение к классу в множестве и применение его метода
        }
    }

    // Удаление группы
    void removeGroup(const string &groupName) {
        auto it = groups.find(groupName);
        if (it != groups.end()) {
            groups.erase(it); // Удаление из множества
        } else {
            throw runtime_error("Группа \"" + groupName + "\" не найдена");
        }
    }
};
// Демонстрация работы
int main() {
    SetConsoleOutputCP(CP_UTF8);
    try {
        SpellFactory factory;

        // Добавление типов заклинаний
        factory.add<atk>("Attack");
        factory.add<def>("Defensive");

        // Создание книги заклинаний
        SpellBook<SpellGroup> book;

        // Добавление групп заклинаний
        book.addGroup("Атакующие");
        book.addGroup("Защитные");

        // Создание заклинаний
        Spell *fireball = factory.createSpell("Attack", "Огненный шар");
        Spell *barrier = factory.createSpell("Defensive", "Барьер");

        // Добавление заклинаний в группы
        book.addSpellToGroup("Атакующие", fireball);
        book.addSpellToGroup("Защитные", barrier);

        // Применение всех заклинаний в книге
        cout << "Книга заклинаний:" << endl;
        book.castAll();

        // Удаление группы
        book.removeGroup("Защитные");
        // Применение оставшихся заклинаний
        cout << "\nКнига заклинаний после удаления группы:" << endl;
        book.castAll();
        book.addSpellToGroup("Атакующие", fireball);
    } catch (const exception &e) {
        cerr << "Ошибка: " << e.what() << endl; //Выводим сообщение ошибки
    }

    return 0;
}
