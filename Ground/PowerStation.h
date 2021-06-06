#ifndef GROUND_POWER_STATION_H
#define GROUND_POWER_STATION_H

#include "GroundWithPrice.h"
#include "../Player/Player.h"
#include "../Player/Output.h"

///发电站类

class PowerStation : public GroundWithPrice
{
private:
	int toll;	//基础过路费

public:
	PowerStation(int _price) : toll(200), GroundWithPrice(_price) {}

	int getToll(int player);
	void buy(int player);
	
	void onStepped(int player);	//路过的时候调用，可以用作菜单
};

#endif // !POWER_STATION_H