#include "villain.h"
#include <string>

Villain::Villain()
{
	std::cout << "Конструктор: Villain (без параметров)\n";
}
Villain::Villain(std::string name, std::string weapon, std::string atrocity, std::string location, std::string skills)
    : name(name), weapon(weapon), skills(skills), location(location), atrocity(atrocity)
{
	std::cout << "Конструктор: Villain (с параметрами)\n";
}
Villain::Villain(Villain &other)
{
	std::cout << "Конструктор: Villain (копирования)\n";
}

void Villain::edit()
{
	char choice;
	std::cout << "1 – Имя;\n"
	          << "2 – Тип оружия;\n"
	          << "3 – Локация;\n"
	          << "4 – Злодеяние;\n"
	          << "5 – Навыки;\n"
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
		std::cout << "Введите локацию >> ";
		getline(std::cin, location);
		break;
	case '4':
		std::cout << "Введите злодеяние >> ";
		getline(std::cin, atrocity);
		break;
	case '5':
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

void Villain::setName(std::string name)
{
	this->name = name;
}
void Villain::setAtrocity(std::string atrocity)
{
	this->atrocity = atrocity;
}
void Villain::setLocation(std::string location)
{
	this->location = location;
}
void Villain::setWeapon(std::string weapon)
{
	this->weapon = weapon;
}
void Villain::setSkills(std::string skills)
{
	this->skills = skills;
}

std::string Villain::getName()
{
	return name;
}
std::string Villain::getAtrocity()
{
	return atrocity;
}
std::string Villain::getLocation()
{
	return location;
}
std::string Villain::getSkills()
{
	return skills;
}
std::string Villain::getWeapon()
{
	return weapon;
}

void Villain::save(std::ostream &os)
{
	os << "Name: " << "\n\t\t" << name << "\n\t"
	   << "Weapon: " << "\n\t\t" << weapon << "\n\t"
	   << "Atrocity: " << "\n\t\t" << atrocity << "\n\t"
	   << "Location: " << "\n\t\t" << location << "\n\t"
	   << "Skills: " << "\n\t\t" << skills << "\n";
}

std::string Villain::type()
{
	return "Villain";
}

void Villain::load(std::istream &is)
{
	std::string key;
	is >> key;
	if (key != "Name:")
		throw "Неверный ключ у объекта Villain";
	is.ignore(2);
	getline(is, name);
	name.erase(0, 2);
	is >> key;
	if (key != "Weapon:")
		throw "Неверный ключ у объекта Villain";
	is.ignore(2);
	getline(is, weapon);
	weapon.erase(0, 2);
	is >> key;
	if (key != "Atrocity:")
		throw "Неверный ключ у объекта Villain";
	is.ignore(2);
	getline(is, atrocity);
	atrocity.erase(0, 2);
	is >> key;
	if (key != "Location:")
		throw "Неверный ключ у объекта Villain";
	is.ignore(2);
	getline(is, location);
	location.erase(0, 2);
	is >> key;
	if (key != "Skills:")
		throw "Неверный ключ у объекта Villain";
	is.ignore(2);
	getline(is, skills);
	skills.erase(0, 2);
}

Villain::~Villain()
{
	std::cout << "Декструктор: Villain\n";
}