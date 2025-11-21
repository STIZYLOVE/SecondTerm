#pragma once
#include "BaseClass.h"
#include <string>

class Warrior : public virtual Npc
{
protected:
    unsigned short strenght{ 31 };
    string weapons[4] = { "кастет", "дубинка", "клинок", "меч" };
public:
    Warrior();
    Warrior(string name, unsigned int health, float damage);

    void GetWeapons();
    void GetInfo() override;
    void Create() override;
    
    bool operator == (const Warrior& warrior) const;
        void operator = (Npc npc);
 
        ~Warrior(); //деструктор всегда без аргументов
    
};


class Wizard : public virtual Npc
{
public:
    class Spell
    {
    protected:
        string name{"заклинание"};
        unsigned short damage{ 0 };
        unsigned short price{ 0 };
        bool isCurse{ false };    
        int timeCast{ 0 };
    public:
        Spell(string name = "заклинание", unsigned short damage = 0, unsigned short price = 0, bool isCurse = false, int timeCast = 0)
        {
            this->name = name;
            this->damage = damage;
            this->price = price;
            this->isCurse = isCurse;
            this->timeCast = timeCast;
        }

        string operator[](unsigned index) const
        {
            switch (index)
            {
            case 0: return name; break;
            case 1: return to_string(damage); break;
            case 2: return to_string(price); break;
            case 3:
                if (isCurse)
                    cout << "Переодичный урон";
                else
                    cout << "Моментальный урон";
                break;
            case 4: return to_string(timeCast); break;
            default: cout << "Такого свойства не существует" << endl; break;
            }
        }

        unsigned short CastSpell()
        {
            cout << "Вы применили заклинание " << name << " на противнике" << endl;
            return damage;
        }
    };
protected:
    unsigned short intellect = 27;
    Spell spells[5] =
    {
        Spell("огненный шар", 20, 10, false, 3),
        Spell("оцепенение", 10, 15, true, 1),
        Spell("магические стрелы", 40, 25, false, 5),
        Spell("торнадо", 15, 30, false, 2),
        Spell("Яд", 10, 10, true, 1)
    };
public:
    Wizard()
    {
        name = "волшебник";
        health = 23;
        damage = 15;
    }
    Wizard(string name, unsigned int health, float damage)
    {
        cout << "кастомный конструктор волшебника" << endl;
        this->name = name;
        this->health = health;
        this->damage = damage;
    }
    void GetInfo() override
    {
        Npc::GetInfo();
        cout << "Интеллект - " << intellect << endl;
        cout << "Доступные заклинания в книге заклинаний: " << endl;
        GetSpellsInfo();
    }
    void GetSpellsInfo()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << " заклинание: ";
            for (int j = 0; j < 5; j++)
            {
                cout << spells[i][j] << endl;
            }
            cout << endl;
        }
    }
    void Create() override
    {
        cout << "Вы создали волшебника" << endl;
        cout << "Введите имя персонажа\t";
        cin >> name;
        GetInfo();
    }
    bool operator == (const Wizard& wizard) const
    {
        return ((wizard.damage == this->damage)
            && (wizard.health == this->health)
            && (wizard.intellect == this->intellect));
    }
    void operator = (Npc npc)
    {
        this->name = npc.GetName();
        this->name = npc.GetHealth();
        this->name = npc.GetDamage();
        this->name = npc.GetLvl();
    }
    ~Wizard()
    {
        cout << name << " испустил дух" << endl;
    }

};


class Paladin : public Warrior, public Wizard
    
{
public:
    Paladin()
    {
        name = "паладин";
        health = 25;
        damage = 12;
        strenght = 27;
    }
    void GetInfo() override
    {
        Warrior::GetInfo();
        cout << "Интеллект - " << intellect << endl;
        cout << "Доступные заклинания в книге заклинаний: ";
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << "заклинание: ";
            for (int j = 0; j < 5; j++)
            {
                cout << spells[i][j] << endl;
            }
        }
    }
    void Create() override
    {
        cout << "Вы создали паладина" << endl;
        cout << "Введите имя персонажа\t";
        cin >> name;
        GetInfo();
        GetWeapons();
    }
    bool operator == (const Paladin& paladin) const
    {
        return ((paladin.damage == this->damage) && (paladin.health == this->health)
            && (paladin.intellect == this->intellect)) && (paladin.strenght == this->strenght);
    }
    void operator = (Npc npc)
    {
        this->name = npc.GetName();
        this->name = npc.GetHealth();
        this->name = npc.GetDamage();
        this->name = npc.GetLvl();
    }
};






