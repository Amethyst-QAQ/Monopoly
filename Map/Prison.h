#ifndef PRISON_H
#define PRISON_H

#include "Ground.h"

class Player;

class Prison : public Ground
{
public:
	Prison() : Ground("Prison") {}
	void onStepped(Player* player) { player->setProperty("Pause",1); }
};

#endif