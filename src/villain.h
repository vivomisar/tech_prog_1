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

	void showInfo() override;
	std::string type() override;
	void save(std::ostream &) override;
	void load(std::istream &) override;
	~Villain();
};
#endif