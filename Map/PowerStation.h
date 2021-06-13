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
	virtual int  getToll();
	virtual bool buy(Player* player);
	virtual bool pledgeByPlayer(Player* player);
	virtual bool redeem(Player* player);

	bool onStepped(Player* player);
};

#endif // !POWER_STATION_H
