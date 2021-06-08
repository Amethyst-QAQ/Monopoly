#ifndef MAP_FATE_GROUND_H
#define MAP_FATE_GROUND_H

#include "Ground.h"
#include "../CardsDrawing/FateSuit.h"

class FateGround :public Ground
{
public:
	FateGround() : Ground("Fate Ground") {}
	void onStepped(Player* player) { FateSuit::instance->draw(player); }
	void show()
	{
		Ground::show();
		Output::instance->print("Name: Fate Ground", "show_name_Fate");
	}
};

#endif