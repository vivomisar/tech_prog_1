#ifndef ENTITY_H
#define ENTITY_H
class Entity
{
  public:
	virtual void showInfo() = 0;
	virtual ~Entity()
	{
	}
};
#endif