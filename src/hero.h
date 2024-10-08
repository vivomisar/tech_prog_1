#ifndef HERO_H
#define HERO_H
#include "entity.h"
class Hero : public Entity
{
  private:
	char name[128];
	char weapon[64];

  public:
	Hero();
};
#endif