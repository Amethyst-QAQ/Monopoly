#ifndef POWER_STATION_H
#define POWER_STATION_H

#include "Ground.h"
#include "Person.h"

class PowerStation : public Ground
{
private:
	int toll;	//基础过路费
	int owner;
	bool pledge;

public:
	PowerStation() : toll(200), owner(0), pledge(false) {}

	void Passed();									//经过的时候调用
	void onStepped();								//路过的时候调用，可以用作菜单
	
	void setOwner(int _owner) { owner = _owner; }

	int getToll(Person a) { return toll * a.getPowerStationNumber(); }	//计算实际过路费
	bool getPledge() { return pledge; }

	void Hypothecate() { pledge = true; }
};

#endif // !POWER_STATION_H