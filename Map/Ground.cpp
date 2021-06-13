#include "Ground.h"
#include "../IO/Output.h"
#include "../Player/Player.h"

using namespace std;

void Ground::show()
{
	string mainText;
	string serverText;

	mainText = "Name: " + getName();
	serverText = "show_name (" + getName() + ")";
	Output::instance->print(mainText, serverText);
}

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
