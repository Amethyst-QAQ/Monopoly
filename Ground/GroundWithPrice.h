#ifndef GROUND_GROUND_WITH_PRICE_H
#define GROUND_GROUND_WITH_PRICE_H

#include <iostream>
#include "Ground.h"
#include "../Player/Menu.h"

class Person;

extern Person* players;

class GroundWithPrice : public Ground
{
protected:
	int owner;		//ӵ����
	int price;		//�۸�
	bool pledge;	//�Ƿ񱻵�Ѻ

public:
	GroundWithPrice(int _price) : owner(0), price(_price), pledge(false) {}

	virtual void onStepped(int player);

	int getOwner() { return owner; }
	int getPrice() { return price; }
	bool getPledge() { return pledge; }

	void setOwner(int _owner) { owner = _owner; }
	void setPrice(int _price) { price = _price; }
	void Hypothecate() { pledge = true; }

	virtual void buy(int player) = 0;
};

#endif