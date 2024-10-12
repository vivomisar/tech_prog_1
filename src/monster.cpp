#include "monster.h"

Monster::Monster()
{
	std::cout << "Конструктор: Monster (без параметров)\n";
}
Monster::Monster(std::string name, std::string desc) : name(name), desc(desc)
{
	std::cout << "Конструктор: Monster (с параметрами)\n";
}
Monster::Monster(Monster &other) : name(other.name), desc(other.name)
{
	std::cout << "Конструктор: Monster (копирования)\n";
}

void Monster::showInfo()
{
	std::cout << "Наименование: " << name << "\nОписание: " << desc << "\n";
}

std::string Monster::type()
{
	return "Monster";
}

void Monster::save(std::ostream &os)
{
	os << "Name: " << "\n\t\t" << name << "\n\t"
	   << "Description: " << "\n\t\t" << desc << "\n";
}

void Monster::load(std::istream &is)
{
	std::string key;
	is >> key;
	if (key != "Name:")
		throw "Неверный ключ у объекта Monster";
	getline(is, name);
	name.erase(0, 3);
	is >> key;
	if (key != "Description:")
		throw "Неверный ключ у объекта Monster";
	getline(is, desc);
	desc.erase(0, 3);
}

Monster::~Monster()
{
	std::cout << "Декструктор: Monster\n";
}