#include "villain.h"
#include <string>

Villain::Villain()
{
	std::cout << "Конструктор: Villain (без параметров)\n";
}
Villain::Villain(std::string name, std::string weapon, std::string atrocity, std::string location, std::string skills)
{
	std::cout << "Конструктор: Villain (с параметрами)\n";
}
Villain::Villain(Villain &other)
{
	std::cout << "Конструктор: Villain (копирования)\n";
}

void Villain::showInfo()
{
	std::cout << "Наименование: " << name << "\nОружие: " << weapon << "\nУмения: " << skills
	          << "\nЗлодеяние: " << atrocity << "\nЛокация: " << location << "\n";
}

void Villain::save(std::ostream &os)
{
	os << "Name: " << "\n\t\t" << name << "\n\t"
	   << "Weapon: " << "\n\t\t" << weapon << "\n\t"
	   << "Atrocity: " << "\n\t\t" << atrocity << "\n\t"
	   << "Location : " << "\n\t\t" << location << "\n\t"
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
	getline(is, name);
	name.erase(0, 3);
	is >> key;
	if (key != "Weapon:")
		throw "Неверный ключ у объекта Villain";
	getline(is, weapon);
	weapon.erase(0, 3);
	is >> key;
	if (key != "Atrocity:")
		throw "Неверный ключ у объекта Villain";
	getline(is, atrocity);
	atrocity.erase(0, 3);
	is >> key;
	if (key != "Location:")
		throw "Неверный ключ у объекта Villain";
	getline(is, location);
	location.erase(0, 3);
	is >> key;
	if (key != "Skills:")
		throw "Неверный ключ у объекта Villain";
	getline(is, skills);
	skills.erase(0, 3);
}

Villain::~Villain()
{
	std::cout << "Декструктор: Villain\n";
}