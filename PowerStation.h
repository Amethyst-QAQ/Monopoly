#ifndef POWER_STATION_H
#define POWER_STATION_H

#include "Ground.h"
#include "Person.h"

class PowerStation : public Ground
{
private:
	int toll;	//������·��
	int owner;
	bool pledge;

public:
	PowerStation() : toll(200), owner(0), pledge(false) {}

	void Passed();									//������ʱ�����
	void onStepped();								//·����ʱ����ã����������˵�
	
	void setOwner(int _owner) { owner = _owner; }

	int getToll(Person a) { return toll * a.getPowerStationNumber(); }	//����ʵ�ʹ�·��
	bool getPledge() { return pledge; }

	void Hypothecate() { pledge = true; }
};

#endif // !POWER_STATION_H