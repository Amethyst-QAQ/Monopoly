#ifndef ARREST_H
#define ARREST_H

#include "Ground.h"
#include "../Player/Player.h"

class Player;

class Arrest : public Ground
{
private:
	int prison;
public:
	Arrest(int _prison) : Ground("Arrest"), prison(_prison) {}
	void onStepped(Player* player) { player->setposition(prison); }
};

#endif // !ARREST_H
