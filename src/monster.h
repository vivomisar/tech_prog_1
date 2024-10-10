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