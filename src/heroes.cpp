#include "heroes.h"

std::ostream &operator<<(std::ostream &os, Heroes &heroes)
{
	os << heroes.type() << ":\n\t";
	heroes.save(os);
	return os;
}