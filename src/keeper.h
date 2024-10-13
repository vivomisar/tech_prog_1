#ifndef KEEPER_H
#define KEEPER_H
#include "hero.h"
#include "monster.h"
#include "villain.h"

class Keeper
{
  private:
	Heroes **data;
	int size;
	int capacity;
	void setSize(int size);
	void normalize(int index);

  public:
	Keeper();
	Keeper(const std::string &path);
	Keeper(Keeper &other);
	Heroes &operator[](int index);
	void add(Heroes *entity);
	void remove(int index);
	void recover(std::istream &is);
	void save(std::ostream &os);
	~Keeper();
};
#endif