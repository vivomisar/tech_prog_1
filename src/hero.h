#ifndef HERO_H
#define HERO_H
#include "entity.h"
#include "my_string.h"
class Hero : public Entity
{
  private:
	MyString name;
	MyString weapon;
	MyString skills;

  public:
	Hero();
	Hero(MyString name, MyString weapon, MyString skills);
	Hero(Hero &other);

	friend std::ostream operator<<(std::ostream &os, const Hero &hero);

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
		throw "У героя нет злодеяний";
	};
	MyString getLocation() override
	{
		throw "У героя нет локации";
	};
	MyString getSkills() override
	{
		return skills;
	};
	MyString getDesc() override
	{
		throw "У героя нет описания";
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
	void setAttrocity(MyString) override{};
	void setLocation(MyString) override{};
	void setSkills(MyString skills) override
	{
		this->skills = skills;
	};
	~Hero();
};
#endif