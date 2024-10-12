#ifndef KEEPER_H
#define KEEPER_H
#include "hero.h"
#include "monster.h"
#include "villain.h"

class Keeper
{
  private:
	Heroes *data;

  public:
	Keeper();
	Keeper(const std::string &path);
	Keeper(Keeper &other);
	void recover(const std::string &path);
	void save(const std::string &path);
};
#endif