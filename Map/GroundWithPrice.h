#ifndef GROUND_GROUND_WITH_PRICE_H
#define GROUND_GROUND_WITH_PRICE_H

#include "Ground.h"
#include "../Player/Menu.h"
#include "../Player/Player.h"

class Player;

extern Player* players;

class GroundWithPrice : public Ground
{
protected:
	int owner;		//拥有者
	int price;		//价格
	bool pledge;	//是否被抵押

public:
	GroundWithPrice() : owner(0), price(100), pledge(false) {}

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