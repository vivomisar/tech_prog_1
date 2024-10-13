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
void Hero::edit()
{
	char choice;
	std::cout << "1 – Имя;\n"
	          << "2 – Тип оружия;\n"
	          << "3 – Навыки;\n"
	          << "0 – Отмена;\n";
	std::cin >> choice;
	std::cin.ignore();
	switch (choice)
	{
	case '1':
		std::cout << "Введите имя >> ";
		getline(std::cin, name);
		break;
	case '2':
		std::cout << "Введите тип оружия >> ";
		getline(std::cin, weapon);
		break;
	case '3':
		std::cout << "Введите умения >> ";
		getline(std::cin, skills);
		break;
	case '0':
		break;
	default:
		throw "Неверный выбор";
		break;
	}
}

void Hero::setName(std::string name)
{
	this->name = name;
}
void Hero::setWeapon(std::string weapon)
{
	this->weapon = weapon;
}
void Hero::setSkills(std::string skills)
{
	this->skills = skills;
}

std::string Hero::getName()
{
	return name;
}
std::string Hero::getSkills()
{
	return weapon;
}
std::string Hero::getWeapon()
{
	return skills;
}

std::string Hero::type()
{
	return "Hero";
}

void Hero::save(std::ostream &os)
{
	os << "Name:" << "\n\t\t" << name << "\n\t"
	   << "Weapon:" << "\n\t\t" << weapon << "\n\t"
	   << "Skills:" << "\n\t\t" << skills << "\n";
}

void Hero::load(std::istream &is)
{
	std::string key;
	is >> key;
	if (key != "Name:")
		throw "Неверный ключ у объекта Hero";
	is.ignore(2);
	getline(is, name);
	name.erase(0, 2);
	is >> key;
	if (key != "Weapon:")
		throw "Неверный ключ у объекта Hero";
	is.ignore(2);
	getline(is, weapon);
	weapon.erase(0, 2);
	is >> key;
	if (key != "Skills:")
		throw "Неверный ключ у объекта Hero";
	is.ignore(2);
	getline(is, skills);
	skills.erase(0, 2);
}

Hero::~Hero()
{
	std::cout << "Деструктор: Hero\n";
}