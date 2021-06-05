#ifndef GROUND_COUNTRY_H
#define GROUND_COUNTRY_H

#include <iostream>
#include <string>
#include "GroundWithPrice.h"
#include "../Player/Person.h"

#define PRICE_1 0        //房屋价格
#define PRICE_2 0		 //旅馆价格

extern bool isServer;

///地产类，继承格子类
class Country : public GroundWithPrice
{
private:
	std::string name;   //地产名称
	int toll;           //过路费
	int housePrice;     //建筑房屋的价格
	int hotelPrice;     //建筑旅馆的价格
	int house;          //房屋数，上限两个
	int hotel;          //旅馆数，上限两个
	int color;			//颜色（拥有同色的所有国家地区就加收过路费为原来的3倍）
	
public:
	Country(std::string _name, int _price, int _toll, int color, int _house_price, int _hotel_price);

	void onStepped(int player);									//路过的时候调用，可以用作菜单

	void setName(std::string _name) { name = _name; }
	void setToll(int _toll) { toll = _toll; }
	void setColor(int _color) { color = _color; }
	void setHousePrice(int _house_price) { housePrice = _house_price; }
	void setHotelPrice(int _hotel_price) { hotelPrice = _hotel_price; }

	std::string getName() { return name; }
	int getToll() { return toll + PRICE_1 * house + PRICE_2 * hotel; }
	int getHouse() { return house; }
	int getHotel() { return hotel; }
	int getColor() { return color; }

	void buy(int player);

	void HouseBuild();	//建造房屋
	void HotelBuild();	//建造旅馆
};

#endif