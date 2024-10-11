#ifndef MONSTER_H
#define MONSTER_H
#include "entity.h"
#include "my_string.h"
class Monster : public Entity
{
  private:
	MyString name;
	MyString desc;

  public:
	Monster();
	Monster(MyString name, MyString desc);
	Monster(Monster &other);

	friend std::ostream operator<<(std::ostream &os, const Monster &monster);
	void showInfo() override;
	MyString getName() override
	{
		return name;
	};
	MyString getWeapon() override
	{
		throw "У монстра нет оружия";
	};
	MyString getAttrocity() override
	{
		throw "У монстра нет злодеяний";
	};
	MyString getLocation() override
	{
		throw "У монстра нет локации";
	};
	MyString getSkills() override
	{
		throw "У монстра нет умений";
	};
	MyString getDesc() override
	{
		return desc;
	};
	void setDesc(MyString desc) override
	{
		this->desc = desc;
	};
	void setName(MyString name) override
	{
		this->name = name;
	};
	void setWeapon(MyString) override{};
	void setAttrocity(MyString) override{};
	void setLocation(MyString) override{};
	void setSkills(MyString) override{};
	~Monster();
};
#endif