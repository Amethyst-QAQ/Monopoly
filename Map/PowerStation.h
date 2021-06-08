#ifndef GROUND_POWER_STATION_H
#define GROUND_POWER_STATION_H

#include "GroundWithPrice.h"
#include "../Player/Player.h"
#include "../IO/Output.h"

class PowerStation : public GroundWithPrice
{
public:
	PowerStation(const std::string& name, int price) : GroundWithPrice(name, price) {}

	void show() { GroundWithPrice::show(); }
	virtual int  getToll() { return this->getOwner()->getProperty("powerStation") * 500; }
	virtual void buy(Player* player)
	{
		GroundWithPrice::buy(player);
		player->setProperty("powerStation", player->getProperty("powerStation") + 1);
	}

	bool onStepped(Player* player);
};

#endif // !POWER_STATION_H
