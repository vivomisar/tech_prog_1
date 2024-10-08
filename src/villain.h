#ifndef VILLAIN_H
#define VILLAIN_H
#include "entity.h"
class Villain : public Entity
{
  private:
	char name[128];
	char weapon[64];
	char atrocity[128];
	char location[256];
};
#endif