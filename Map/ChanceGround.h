#ifndef MAP_CHANCE_GROUND_H
#define MAP_CHANCE_GROUND_H

#include "Ground.h"
#include "../CardsDrawing/ChanceSuit.h"

class ChanceGround :public Ground
{
public:
	ChanceGround() : Ground("Chance Ground") {}
	bool onStepped(Player* player) 
	{ 
		if (Ground::onStepped(player))
			return true;
		ChanceSuit::instance->draw(player); 
		return true;
	}
};

#endif