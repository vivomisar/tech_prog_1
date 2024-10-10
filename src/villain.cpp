#include "villain.h"

Villain::Villain()
{
	std::cout << "Конструктор: Villain (без параметров)\n";
}
Villain::Villain(MyString name, MyString weapon, MyString atrocity, MyString location, MyString skills)
{
	std::cout << "Конструктор: Villain (с параметрами)\n";
}
Villain::Villain(Villain &other)
{
	std::cout << "Конструктор: Villain (копирования)\n";
}