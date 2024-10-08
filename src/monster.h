#ifndef MONSTER_H
#define MONSTER_H
#include "entity.h"
class Monster : public Entity
{
  private:
	char name[128];
	char desc[256];
};
#endif