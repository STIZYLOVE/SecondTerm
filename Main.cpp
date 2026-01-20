#include <iostream>
#include <fstream> 
#include <chrono>
#include <thread>
#include <cstdlib>
#include <limits>

#include "windows.h"

#include "Ninja.h"
#include "Warrior.h"
#include "Assasin.h"
#include "NpcClass.h"
#include "playerClass.h"
#include "Enemy.h"


using namespace std;

enum class ValueQuality
{
    МУСОР, ОБЫЧНОЕ, РЕДКОЕ, МИФИЧЕСКОЕ, ЛЕГЕНДАРНОЕ
};

struct Treasure
{
    Treasure() = default;
    string name{ "добыча" };
    ValueQuality quality = ValueQuality::МИФИЧЕСКОЕ;
    unsigned int price{ 0 };
    Treasure(ValueQuality quality)
    {
        switch (quality)
        {
        case ValueQuality::МУСОР:
            cout << "качество плохое\n";
            break;
        case ValueQuality::ОБЫЧНОЕ:
            cout << "качество средненькое\n";
            break;
        case ValueQuality::РЕДКОЕ:
            cout << "качество хорошее\n";
            break;
        case ValueQuality::МИФИЧЕСКОЕ:
            cout << "качество крутое\n";
            break;
        case ValueQuality::ЛЕГЕНДАРНОЕ:
            cout << "качество идеальное\n";
            break;
        default:
            break;
        }
    }
};

struct Сloth : Treasure
{
    Сloth(ValueQuality quality) : Treasure(quality) {};
    string valueSite[5]{ "Ботинки", "Поножи", "Нагрудник", "Шлем"};
    string site{ NULL };
    unsigned short armor{ 1 };
};

enum class CharacterType {
    UNKNOWN,
    WARRIOR,
    ASSASIN,
    NINJA
};

unsigned short TestChoise(unsigned short maxChoise, string text)
{
    unsigned short choise = 1;
    cin >> choise;
    while (choise > maxChoise || choise < 1)
    {
        cout << text << endl;
        cin >> choise;
    }
    return choise;
};

unsigned short TestChoise(unsigned short maxChoise)
{
    unsigned short choise = 1;
    cin >> choise;
    while (choise > maxChoise || choise < 1)
    {
        cout << "Такого выбора не существует!" << endl;
        cin >> choise;
    }
    return choise;
};

unique_ptr<Npc> CreateCharacter(CharacterType type)
{
    switch (type)
    {
    case CharacterType::UNKNOWN:
        return make_unique<Npc>();
        break;
    case CharacterType::WARRIOR:
        return make_unique<Warrior>();
        break;
    case CharacterType::ASSASIN:
        return make_unique<Assasin>();
        break;
    case CharacterType::NINJA:
        return make_unique<Ninja>();
        break;
    default:
        invalid_argument("Неизвестный тип персонажа");
        break;
    }
}

void Pause(bool needText)
{
    if (needText)
        cout << "Enter чтобы продолжить...";
    cin.get();
    cout << endl;
}

void printSlowly(const string& text, double charsPerSecond, bool needPause)
{
    if (charsPerSecond <= 0) {
        cout << text;
        if (needPause) Pause(false);
        return;
    }

    auto delay = chrono::duration<double>(1.0 / charsPerSecond);

    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(delay);
    }

    if (needPause) {
        Pause(false);
    }
}

void ShowName(string name)
{
    cout << "[" << name << "]" << endl;
}

void ClearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Player* player = new Player();

    ShowName("Незнакомец");
    printSlowly("Привет, путник\nПрисядь у костра и расскажи о себе\nТы кем будешь?\n\t", 20, false);
    cout << "1 - Воин\n\t2 - Ассасин\n\t3 - Нинзя\n";

    unique_ptr<Npc> character;
    switch (TestChoise(3, "Чего-чего ты не ошибся ли?\nНе мог бы ты повторить"))
    {
    case 1:
        character = CreateCharacter(CharacterType::WARRIOR);
        break;
    case 2:
        character = CreateCharacter(CharacterType::ASSASIN);
        break;
    case 3:
        character = CreateCharacter(CharacterType::NINJA);
        break;
    }

    ClearScreen();

    player->Create(move(character));

    auto playerCharacter = player->GetCharacter();

    Pause(true);

    ClearScreen();

    ShowName("Незнакомец");
    printSlowly("Ну что, приятно познакомится ", 20, false);
    printSlowly(playerCharacter->GetName() + "\n", 2, false);
    printSlowly("Я Марк, воин! Ты чего забыл в этом лесу?", 20, true);

    ShowName(playerCharacter->GetName());
    printSlowly("Взаимно! Я блуждаю в этих лесах, чтобы найти полезные ", 20, false);
    printSlowly("артефакты", 4, true);

    return 0;
}
