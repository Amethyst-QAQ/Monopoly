#include "PowerStation.h"

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