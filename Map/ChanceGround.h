#ifndef MAP_CHANCE_GROUND_H
#define MAP_CHANCE_GROUND_H

#include "Ground.h"
#include "../CardsDrawing/ChanceSuit.h"

class ChanceGround :public Ground
{
public:
	ChanceGround() : Ground("Chance Ground") {}
	void onStepped(Player* player) { ChanceSuit::instance->draw(player); }
	void show()
	{
		Ground::show();
		Output::instance->print("Name: Chance Ground", "show_name_Chance");
	}
};

#endif