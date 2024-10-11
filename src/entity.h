#ifndef ENTITY_H
#define ENTITY_H

#include "my_string.h"
#include <iostream>

class Entity
{
  public:
	virtual void showInfo() = 0;
	virtual MyString getName() = 0;
	virtual MyString getWeapon() = 0;
	virtual MyString getAttrocity() = 0;
	virtual MyString getLocation() = 0;
	virtual MyString getSkills() = 0;
	virtual MyString getDesc() = 0;
	virtual void setDesc(MyString) = 0;
	virtual void setName(MyString) = 0;
	virtual void setWeapon(MyString) = 0;
	virtual void setAttrocity(MyString) = 0;
	virtual void setLocation(MyString) = 0;
	virtual void setSkills(MyString) = 0;
	virtual ~Entity()
	{
		std::cout << "Деструктор: Entity\n";
	}
};
#endif