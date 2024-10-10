#include "hero.h"
#include "my_string.h"

Hero::Hero()
{
	std::cout << "Конструктор: Hero (без параметров)\n";
}
Hero::Hero(MyString name, MyString weapon, MyString skills)
{
	std::cout << "Конструктор: Hero (с параметрами)\n";
}
Hero::Hero(Hero &other)
{
	std::cout << "Конструктор: Hero (копирования)\n";
}