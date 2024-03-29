#ifndef MAP_GROUND_WITH_PRICE_H
#define MAP_GROUND_WITH_PRICE_H

#include "Ground.h"

class Player;

class GroundWithPrice : public Ground
{
protected:
	Player *owner;
	int price;
	bool pledge;
public:
	GroundWithPrice(const std::string &name, int _price) :
		Ground(name),
		owner(nullptr),
		price(_price),
		pledge(false) {}
	
	virtual void show();

	Player *getOwner() { return owner; }
	int getPrice() { return price; }
	bool getPledge() { return pledge; }

	void setOwner(Player *owner) { this->owner = owner; }
	void setPrice(int price) { this->price = price; }
	void setPledge(bool pledge) { this->pledge = pledge; }

	virtual int getToll() = 0;

	virtual bool buy(Player *player);
	virtual bool pledgeByPlayer(Player *player);
	virtual bool redeem(Player *player);

	virtual bool onStepped(Player *player);
};

#endif // !MAP_GROUND_WITH_PRICE_H
