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
	Villain(Villain &other);
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