#include "Beginning.h"
#include "../Player/Player.h"
#include "../IO/Output.h"

void Beginning::onPassed(Player *player)
{
	Ground::onPassed(player);
	player->setMoney(player->getMoney() + 2000);
	Output::instance->print(
		"Passed beginning, add 2000 yuan.",
		"beginning"
	);
}
