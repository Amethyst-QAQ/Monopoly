#ifndef GROUND_GROUND_WITH_PRICE_H
#define GROUND_GROUND_WITH_PRICE_H

#include <iostream>
#include "Ground.h"
#include "../Player/Menu.h"

class GroundWithPrice : public Ground
{
private:
	int owner;		//拥有者
	int price;		//价格
	bool pledge;	//是否被抵押

public:
	GroundWithPrice(int _price) : owner(0), price(_price), pledge(false) {}

	virtual void onStepped();

	int getOwner() { return owner; }
	int getPrice() { return price; }
	bool getPledge() { return pledge; }

	void setOwner(int _owner) { owner = _owner; }
	void setPrice(int _price) { price = _price; }
	void Hypothecate() { pledge = true; }
};

#endif