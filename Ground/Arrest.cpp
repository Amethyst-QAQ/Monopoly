#include "Arrest.h"

void Arrest::onStepped(int player)
{
	std::string mainText = "You are arrested.You have to be suspended for a round.";
	std::string serverText = "arrest";
	Output::instance->print(mainText, serverText);

	Player& p = players[player];

	p.setPosition(prison);
	prison->beArrested(player);
}
