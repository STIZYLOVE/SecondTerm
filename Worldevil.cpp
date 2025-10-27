#include "Worldevil.h"

Worldevil::Worldevil(string n, int h, float d, unsigned short l, bool isA) :name(n), health(h), damage(d), lvl(l), isAlive(isA)
{

}
Worldevil::Worldevil() : Worldevil("Первак", 1, 1, 1, true)
{
	cout << "работает" << endl;
}
Worldevil::Worldevil(string n) : Worldevil(n, health, damage, lvl, isAlive)
{
	cout << "Привет " << n << endl;
}
Worldevil::Worldevil(string n, int h) : Worldevil(n, h, damage, lvl, isAlive)
{
	cout << "Привет " << n << " ХП: " << h << endl;
}
Worldevil::~Worldevil()
{
	cout << "Вражина студента " << name << "Повержен";
}
;
