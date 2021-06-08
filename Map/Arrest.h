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

	void show()
	{ 
		Ground::show();
		Output::instance->print("Name: Arrest Ground", "show_name_Arrest");
	}

	void onStepped(Player* player)
	{
		if (Ground::onStepped(player))
			return true;

		player->setPosition(prison); 
		player->setProperty("Pause", 1);
		Output::instance->print(
			"You are arrested",
			"arrested"
		);
		return true;
	}
};

#endif // !ARREST_H
