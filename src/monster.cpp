#include "monster.h"

Monster::Monster()
{
	std::cout << "Конструктор: Monster (без параметров)\n";
}
Monster::Monster(MyString name, MyString desc)
{
	std::cout << "Конструктор: Monster (с параметрами)\n";
}
Monster::Monster(Monster &other)
{
	std::cout << "Конструктор: Monster (копирования)\n";
}