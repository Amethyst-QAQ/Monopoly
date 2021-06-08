#include "Ground.h"
#include "../IO/Output.h"
#include "../Player/Player.h"

using namespace std;

void Ground::onStepped(Player *player)
{
	Output::instance->print(
		"Player " + player->getName() + " has stepped on Ground " + name,
		"step(" + player->getName() + ")(" + to_string(position) + ")"
	);
}

void Ground::onPassed(Player *player)
{
}
