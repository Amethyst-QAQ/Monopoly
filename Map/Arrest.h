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
	void onStepped(Player* player)
	{
		player->setPosition(prison); 
		player->setProperty("Pause", 1);
		Output::instance->print(
			"You are arrested",
			"arrested"
		);
	}
};

#endif // !ARREST_H
