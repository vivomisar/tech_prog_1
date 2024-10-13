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

	void edit() override;
	std::string type() override;
	void save(std::ostream &) override;
	void load(std::istream &) override;

	void setName(std::string);
	void setDesc(std::string);

	std::string getName();
	std::string getDesc();

	~Monster();
};
#endif