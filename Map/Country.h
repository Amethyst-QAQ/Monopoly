#ifndef MAP_COUNTRY_H
#define MAP_COUNTRY_H

#include "GroundWithPrice.h"

class Country : public GroundWithPrice
{
private:
	int color;
	int houseNum;
	int getBaseToll();
public:
	Country(const std::string &name, int price, int _color):
		GroundWithPrice(name, price),
		color(_color),
		houseNum(0){}

	virtual int getToll();
	int getColor() { return color; }
	int getHousePrice();

	void build(Player *player);

	virtual void buy(Player *player);
	virtual bool onStepped(Player *player);
};

#endif // !MAP_COUNTRY_H
