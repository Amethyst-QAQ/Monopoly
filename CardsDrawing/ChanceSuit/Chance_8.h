#ifndef CARDS_DRAWING_CHANCE_SUIT_CHANCE_8_H
#define CARDS_DRAWING_CHANCE_SUIT_CHANCE_8_H

#include "../Chance.h"
#include "../../Player/Player.h"

//²ð·¿×Ó
class Player;

class Chance_8 :public Chance
{
public:
	Chance_8() :Chance("", 1) {}
	void doEvent(Player* player) { }
};

#endif
