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

	void showInfo() override;
	MyString getName() override;
	MyString getWeapon() override;
	MyString getAttrocity() override;
	MyString getLocation() override;
	MyString getSkills() override;
	void setName(MyString) override;
	void setWeapon(MyString) override;
	void setAttrocity(MyString) override;
	void setLocation(MyString) override;
	void setSkills(MyString) override;
};
#endif