#include "monster.h"

Monster::Monster()
{
	std::cout << "Конструктор: Monster (без параметров)\n";
}
Monster::Monster(MyString name, MyString desc) : name(name), desc(desc)
{
	std::cout << "Конструктор: Monster (с параметрами)\n";
}
Monster::Monster(Monster &other) : name(other.getName()), desc(other.getDesc())
{
	std::cout << "Конструктор: Monster (копирования)\n";
}