#include <iostream>
#include "windows.h"
#include "BaseClass.h"
#include "StartClasses.h"

using namespace std;

enum class ValueQuality
{
    trash, common, rare, mythic, legendary
};
enum class characterTyper
{
    warrior, wizard, paladin
};
enum class mainMenu
{
    newGame, loadGame, settings, quit
};
enum class weaponsType
{
    dagger, magicWand, magicSword, morgenshtern, hammer
};
enum class spellsType
{
    quickSpell, hardSpell, areaSpell, shieldSpell, ultimateSpell
};

enum class CharacterType
{
    UNKNOWN =0,
    WARRIOR,
    WIZARD,
    PALADIN
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
    case CharacterType::WIZARD:
        return make_unique<Wizard>();
        break;
    case CharacterType::PALADIN:
        return make_unique<Paladin>();
        break;
    default:
        throw
            invalid_argument("Неизвестный тип персонажа");
        break;
    }
}

struct Treasure
{
    Treasure() = default;
    string name{ "добыча" };
    ValueQuality quality = ValueQuality::trash;
    unsigned int price{ 0 };
    Treasure(ValueQuality quality)
    {
        switch (quality)
        {
        case ValueQuality::trash:
            cout << "Качество плохое\n";
            break;
        case ValueQuality::common:
            cout << "Качество средненькое\n";
            break;
        case ValueQuality::rare:
            cout << "Качество хорошее\n";
            break;
        case ValueQuality::mythic:
            cout << "Качество крутое\n";
            break;
        case ValueQuality::legendary:
            cout << "Качество идеальное\n";
            break;
        default:
            break;
        }
    }
};
struct Cloth : Treasure
{
    Cloth(ValueQuality quality) : Treasure(quality) {};
    string valueSite[5]{ "ботинки","поножи","нагрудник","шлем","пояс" };
    string site{ NULL };  
    unsigned int armor{ 1 };
};
struct Weapon
{
    Weapon() = default;
    string name{ "Оружие" };
    weaponsType weapon = weaponsType::dagger;
    ValueQuality quality = ValueQuality::trash;
    unsigned short damage{ 1 };
};
struct Spell
{
    Spell() = default;
    string name{ "Заклинание" };
    spellsType weapon = spellsType::quickSpell;
    unsigned short damage{ 1 };
    unsigned short manaCost{ 1 };
};


int main()
{
    setlocale(LC_ALL, ".UTF-8");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Player* player = new Player();

    cout << "Привет путник\nПрисядь у костра и расскажи о себе\nТы впервые тут?\n\t1 - новый персонаж\n\t2 - загрузить";

    if (TestChoise(2, "Наверное ты ошибся, повтори снова"))
    {
        cout << "Расскажи о своих навыках \n\t1 - Воин\n\t2 - Волшебник\n\t3 - Паладин";
        unique_ptr<Npc> character;
        switch (TestChoise(4, "Такого еще не было в наших краях\nНе мог бы ты повторить"))
        {
            case 1:
                character = CreateCharacter(CharacterType::WARRIOR);
                break;
            case 2:
                character = CreateCharacter(CharacterType::WIZARD);
                break;
            case 3:
                character = CreateCharacter(CharacterType::PALADIN);
                break;
        } 
        player->Create(move(character));
    }


    return 0;
}
