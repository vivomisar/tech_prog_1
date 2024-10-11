#ifndef VILLAIN_H
#define VILLAIN_H
#include "entity.h"
#include "my_string.h"

class Villain : public Entity
{
  private:
	MyString name;
	MyString weapon;
	MyString atrocity;
	MyString location;
	MyString skills;

  public:
	Villain();
	Villain(MyString name, MyString weapon, MyString atrocity, MyString location, MyString skills);

	friend std::ostream operator<<(std::ostream &os, const Villain &villain);
	Villain(Villain &other);
	void showInfo() override;
	MyString getName() override
	{
		return name;
	};
	MyString getWeapon() override
	{
		return weapon;
	};
	MyString getAttrocity() override
	{
		return atrocity;
	};
	MyString getLocation() override
	{
		return location;
	};
	MyString getSkills() override
	{
		return skills;
	};
	MyString getDesc() override
	{
		throw "У злодея нет описания";
	};
	void setDesc(MyString) override{};
	void setName(MyString name) override
	{
		this->name = name;
	};
	void setWeapon(MyString weapon) override
	{
		this->weapon = weapon;
	};
	void setAttrocity(MyString atrocity) override
	{
		this->atrocity = atrocity;
	};
	void setLocation(MyString location) override
	{
		this->location = location;
	};
	void setSkills(MyString skills) override
	{
		this->skills = skills;
	};
	~Villain();
};
#endif