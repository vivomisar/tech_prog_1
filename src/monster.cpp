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

void Monster::edit()
{

	char choice;
	std::cout << "1 – Наименовние;\n"
	          << "2 – Описание;\n"
	          << "0 – Отмена;\n";
	std::cin >> choice;
	std::cin.ignore();
	switch (choice)
	{
	case '1':
		std::cout << "Введите наименование >> ";
		getline(std::cin, name);
		break;
	case '2':
		std::cout << "Введите описание >> ";
		getline(std::cin, desc);
		break;
	case '0':
		break;
	default:
		throw "Неверный выбор";
		break;
	}
}

void Monster::setName(std::string name)
{
	this->name = name;
}
void Monster::setDesc(std::string desc)
{
	this->desc = desc;
}

std::string Monster::getName()
{
	return name;
}
std::string Monster::getDesc()
{
	return desc;
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
	is.ignore(2);
	getline(is, name);
	name.erase(0, 2);
	is >> key;
	if (key != "Description:")
		throw "Неверный ключ у объекта Monster";
	is.ignore(2);
	getline(is, desc);
	desc.erase(0, 2);
}

Monster::~Monster()
{
	std::cout << "Декструктор: Monster\n";
}