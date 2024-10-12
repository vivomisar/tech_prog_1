#include "hero.h"
#include <cstdio>

Hero::Hero()
{
	std::cout << "Конструктор: Hero (без параметров)\n";
}
Hero::Hero(std::string name, std::string weapon, std::string skills) : name(name), weapon(weapon), skills(skills)
{
	std::cout << "Конструктор: Hero (с параметрами)\n";
}
Hero::Hero(Hero &other) : name(other.name), weapon(other.weapon), skills(other.skills)
{
	std::cout << "Конструктор: Hero (копирования)\n";
}

void Hero::showInfo()
{
	std::cout << "Наименование: " << name << "\nОружие: " << weapon << "\nУмения: " << skills << "\n";
}

std::string Hero::type()
{
	return "Hero";
}

void Hero::save(std::ostream &os)
{
	os << "Name: " << "\n\t\t" << name << "\n\t"
	   << "Weapon: " << "\n\t\t" << weapon << "\n\t"
	   << "Skills: " << "\n\t\t" << skills << "\n";
}

void Hero::load(std::istream &is)
{
	std::string key;
	is >> key;
	if (key != "Name:")
		throw "Неверный ключ у объекта Hero";
	getline(is, name);
	name.erase(0, 3);
	is >> key;
	if (key != "Weapon:")
		throw "Неверный ключ у объекта Hero";
	getline(is, weapon);
	weapon.erase(0, 3);
	is >> key;
	if (key != "Skills:")
		throw "Неверный ключ у объекта Hero";
	getline(is, skills);
	skills.erase(0, 3);
}

Hero::~Hero()
{
	std::cout << "Деструктор: Hero\n";
}