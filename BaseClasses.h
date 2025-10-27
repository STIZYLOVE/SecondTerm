#pragma once
#include <iostream>

using namespace std;

class Npc
{
protected:

    string name{ "персонаж" };
    unsigned int health{ 10 };
    float damage{ 5 };
    unsigned short lvl{ 1 };

public:

    Npc();
    virtual void GetInfo();
    virtual void Create() {};
    ~Npc();

};