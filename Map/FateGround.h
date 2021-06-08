#ifndef MAP_FATE_GROUND_H
#define MAP_FATE_GROUND_H

#include "Ground.h"
#include "../CardsDrawing/FateSuit.h"

class FateGround :public Ground
{
public:
	FateGround() : Ground("Fate Ground") {}
	void onStepped(Player* player) { FateSuit::instance->draw(player); }
};

#endif