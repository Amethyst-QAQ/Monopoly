#ifndef PRISON_H
#define PRISON_H

#include "Ground.h"
#include "../Player/Player.h"

class Player;

class Prison : public Ground
{
public:
	Prison() : Ground("Prison") {}
	void show()
	{
		Ground::show();
		Output::instance->print("Name: Prison Ground", "show_name_Prison");
	}
};

#endif