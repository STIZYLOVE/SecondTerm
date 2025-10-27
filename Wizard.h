#pragma once
#include "BaseClasses.h"
#include <iostream>

class Wizard : virtual public Npc
{
protected:
    unsigned short intellect = 27;
    string spell[4] = { "вспышка", "магисческая стрела", "огненный шар", "метеоритный дождь" };
public:

    Wizard();
    Wizard(string name, unsigned int health, float damage);
    void GetInfo() override;
    void CastSpell();
    void Create() override;
    //перегрузка +
    Wizard operator + (const Wizard& wizard)
    {
        return Wizard
        (this->name,
        (this->health+wizard.health),
        (this->damage+wizard.damage));
    }

    Paladin operator + (const Warrior& warrior)
    {
        return Paladin
        (this->name,
        (this->health + warrior.health),
        (this->damage + warrior.damage));
    }

    ~Wizard();
};