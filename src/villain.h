#ifndef VILLAIN_H
#define VILLAIN_H
#include "heroes.h"

class Villain : public Heroes
{
  private:
	std::string name;
	std::string weapon;
	std::string atrocity;
	std::string location;
	std::string skills;

  public:
	Villain();
	Villain(std::string name, std::string weapon, std::string atrocity, std::string location, std::string skills);
	Villain(Villain &other);

	friend std::ostream operator<<(std::ostream &os, const Villain &villain);

	void edit() override;
	std::string type() override;
	void save(std::ostream &) override;
	void load(std::istream &) override;

	void setName(std::string);
	void setAtrocity(std::string);
	void setLocation(std::string);
	void setWeapon(std::string);
	void setSkills(std::string);

	std::string getName();
	std::string getAtrocity();
	std::string getLocation();
	std::string getSkills();
	std::string getWeapon();
	~Villain();
};
#endif