#ifndef MAP_BEGINNING_H
#define MAP_BEGINNING_H

#include "Ground.h"

class Beginning : public Ground
{
public:
	Beginning() : Ground("Beginning"){}
	virtual void onPassed(Player *player);
};

#endif // !MAP_BEGINNING_H
