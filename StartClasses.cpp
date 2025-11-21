#include "StartClasses.h"

Warrior::Warrior() //конструктор по умолчанию, когда нет аргументов
{
    name = "воин";
    health = 35;
    damage = 10;
}
//кастомный конструктор
Warrior::Warrior(string name, unsigned int health, float damage)
{
    cout << "кастомный конструктор война" << endl;
    this->name = name;
    this->health = health;
    this->damage = damage;
}

void Warrior::GetWeapons()
{
    cout << name << " взял в руки " << weapons[lvl - 1];
}
void Warrior::GetInfo()   //полиморфизм (перегрузка для метода)
{
    Npc::GetInfo();
    cout << "Сила - " << strenght << endl;
    cout << "Доступное оружие - ";
    for (int i = 0; i < lvl; i++)
    {
        cout << weapons[i] << endl;
    }
}
void Warrior::Create() 
{
    cout << "Вы создали война" << endl;
    cout << "Введите имя персонажа\t";
    cin >> name;
    GetInfo();
    GetWeapons();
}
bool Warrior::operator == (const Warrior& warrior) const
{
    return ((warrior.damage == this->damage) && (warrior.health == this->health)
        && (warrior.strenght == this->strenght));
}
void Warrior::operator = (Npc npc)
{
    if (this != &npc) 
    {
        this->name = npc.GetName();
        this->name = npc.GetHealth();
        this->name = npc.GetDamage();
        this->name = npc.GetLvl();
    }
}

//деструктор - метод, который вызывается автоматически при высвобождении памяти
//при окончании работы с экземпляром класса (нельзя вызвать вручную)
Warrior::~Warrior() //деструктор всегда без аргументов
{
    cout << name << " пал смертью храбрых" << endl;
}
