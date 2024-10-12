#ifndef HERO_H
#define HERO_H
#include "heroes.h"
class Hero : public Heroes
{
  private:
	std::string name;
	std::string weapon;
	std::string skills;

  public:
	Hero();
	Hero(std::string name, std::string weapon, std::string skills);
	Hero(Hero &other);

	friend std::ostream operator<<(std::ostream &os, const Hero &hero);

	void showInfo() override;
	std::string type() override;
	void save(std::ostream &) override;
	void load(std::istream &) override;
	~Hero();
};
#endif