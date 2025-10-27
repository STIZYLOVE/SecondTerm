#include "BaseClasses.h"

Npc::Npc()
{
	cout << "Вы создали Npc" << endl;
}

void Npc::GetInfo()
{
	cout << "Имя - " << name << endl;
	cout << "Здоровье - " << health << endl;
	cout << "Урон - " << damage << endl;
}

Npc::~Npc()
{
	cout << "Npc удален" << endl;
}
