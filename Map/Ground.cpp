#include "Ground.h"
#include "../IO/Output.h"
#include "../Player/Player.h"

using namespace std;

bool Ground::onStepped(Player *player)
{
	Output::instance->print(
		"Player " + player->getName() + " has stepped on Ground " + name,
		"step(" + player->getName() + ")(" + to_string(position) + ")"
	);

	return false;
}

void Ground::onPassed(Player *player)
{
}
