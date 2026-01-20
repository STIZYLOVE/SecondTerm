#pragma once
using namespace std;
#include <fstream> 
#include <iostream>

class Npc
{
protected:
	string name{ "персонаж" };
	unsigned int health{ 10 };
	float damage{ 5 };
	unsigned short lvl{ 1 };
public:
	string GetName() const
	{
		return name;
	}
	unsigned int GetHealth() const
	{
		return health;
	}
	float GetDamage() const
	{
		return damage;
	}
	unsigned short GetLvl() const
	{
		return lvl;
	}

	virtual void GetInfo()
	{
		cout << "Имя - " << name << endl;
		cout << "Здоровье - " << health << endl;
		cout << "Урон - " << damage << endl;
	}
	virtual void Create() {};

	virtual ~Npc() = default;
};
