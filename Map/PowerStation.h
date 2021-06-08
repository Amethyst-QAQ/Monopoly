#ifndef GROUND_POWER_STATION_H
#define GROUND_POWER_STATION_H

#include "GroundWithPrice.h"
#include "../Player/Player.h"
#include "../Player/Output.h"

///����վ��

class PowerStation : public GroundWithPrice
{
private:
	int toll;	//������·��
	int num;
public:
	PowerStation(int _num) : toll(100), num(_num),GroundWithPrice() {}
	PowerStation(int _num, int _price) : toll(100), num(_num), GroundWithPrice(_price) {}

	int getToll(int player);
	void buy(int player);
	
	void onStepped(int player);	//·����ʱ����ã����������˵�
};

#endif // !POWER_STATION_H