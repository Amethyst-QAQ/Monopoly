#ifndef CARDS_DRAWING_CHANCE_SUIT_CHANCE_7_H
#define CARDS_DRAWING_CHANCE_SUIT_CHANCE_7_H

#include "../Chance.h"
#include "../../Player/Player.h"

class Player;

class Chance_7 :public Chance
{
public:
	Chance_7() :Chance("ÓÐÉË·ç»¯(ËðÊ§800)", 3) {}
	void doEvent(Player* player) { player->setMoney(player->getMoney() - 800); }
};

#endif#pragma once
