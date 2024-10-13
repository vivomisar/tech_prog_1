#ifndef HEROES_H
#define HEROES_H

#include <iostream>
#include <string>

class Heroes
{
  public:
	Heroes()
	{
		std::cout << "Конструктор: Heroes\n";
	};

	friend std::ostream &operator<<(std::ostream &os, Heroes &heroes);

	virtual void edit() = 0;
	virtual std::string type() = 0;
	virtual void save(std::ostream &) = 0;
	virtual void load(std::istream &) = 0;

	virtual ~Heroes()
	{
		std::cout << "Деструктор: Heroes\n";
	}
};
#endif