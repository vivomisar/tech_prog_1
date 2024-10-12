#ifndef MONSTER_H
#define MONSTER_H
#include "heroes.h"
class Monster : public Heroes
{
  private:
	std::string name;
	std::string desc;

  public:
	Monster();
	Monster(std::string name, std::string desc);
	Monster(Monster &other);

	friend std::ostream operator<<(std::ostream &os, const Monster &monster);
	void showInfo() override;
	std::string type() override;
	void save(std::ostream &) override;
	void load(std::istream &) override;

	~Monster();
};
#endif