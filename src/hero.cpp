#include "hero.h"
#include "my_string.h"

Hero::Hero()
{
	std::cout << "Конструктор: Hero (без параметров)\n";
}
Hero::Hero(MyString name, MyString weapon, MyString skills) : name(name), weapon(weapon), skills(skills)
{
	std::cout << "Конструктор: Hero (с параметрами)\n";
}
Hero::Hero(Hero &other) : name(other.getName()), weapon(other.getWeapon()), skills(other.getSkills())
{
	std::cout << "Конструктор: Hero (копирования)\n";
}

void Hero::showInfo()
{
	std::cout << "Наименование: " << name << "\nОружие: " << weapon << "\nУмения: " << skills << "\n";
}

Hero::~Hero()
{
	std::cout << "Деструктор: Hero\n";
}