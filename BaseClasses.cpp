#include "BaseClass.h"

string Npc::GetName()
{
    return name;
}
unsigned int Npc::GetHealth()
{
    return health;
}
float Npc::GetDamage()
{
    return damage;
}
unsigned int Npc::GetLvl()
{
    return lvl;
}
void Npc::GetInfo() //метод класса
{
    cout << "Имя - " << name << endl;
    cout << "Здоровье - " << health << endl;
    cout << "Урон - " << damage << endl;
}
