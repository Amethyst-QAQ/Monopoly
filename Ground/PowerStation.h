#ifndef GROUND_POWER_STATION_H
#define GROUND_POWER_STATION_H

#include "GroundWithPrice.h"
#include "../Player/Person.h"

class PowerStation : public GroundWithPrice
{
private:
	int toll;	//������·��

public:
	PowerStation(int _price) : toll(200), GroundWithPrice(_price) {}
	
	void onStepped();	//·����ʱ����ã����������˵�
};

#endif // !POWER_STATION_H