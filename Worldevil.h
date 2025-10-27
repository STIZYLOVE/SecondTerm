#pragma once
#ifndef WORLDEVIL_H
#define WORLDEVIL_H

#include <iostream>
#include <windows.h>

using namespace std;

class Worldevil {
protected:

    string name{ "персонаж" };
    unsigned int health{ 10 };
    float damage{ 5 };
    unsigned short lvl{ 1 };
    bool isAlive{ true };

public:

    Worldevil(string n, int h, float d, unsigned short l, bool isA);
    Worldevil();
    Worldevil(string n);
    Worldevil(string n, int h);
    ~Worldevil();

};

#endif // !WORLDEVIL_H

