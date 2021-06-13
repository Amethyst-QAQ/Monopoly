#include "PowerStation.h"

int PowerStation::getToll()
{ 
	int num = this->getOwner()->getProperty("powerStation");
	int toll = price;
	for (int i = 0; i < num; i++)
		toll *= 4;
	return toll / 4;
}

bool PowerStation::pledgeByPlayer(Player* player)
{
	if (GroundWithPrice::pledgeByPlayer(player))
	{
		player->setProperty("powerStation", player->getProperty("powerStation") - 1);
		return true;
	}
	return false;
}

bool PowerStation::redeem(Player* player)
{
	if (GroundWithPrice::redeem(player))
	{
		player->setProperty("powerStation", player->getProperty("powerStation") + 1);
		return true;
	}
	return false;
}

bool PowerStation::buy(Player* player)
{
	if (GroundWithPrice::buy(player))
	{
		player->setProperty("powerStation", player->getProperty("powerStation") + 1);
		return true;
	}
	return false;
}

bool PowerStation::onStepped(Player* player)
{
	if (GroundWithPrice::onStepped(player))
		return true;
	if (owner == player)
	{
		std::string mainText = "The ground is yours.";
		std::string serverText = "Your_ground";
		Output::instance->print(mainText, serverText);

		return true;
	}
}