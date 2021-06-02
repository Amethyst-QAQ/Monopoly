#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include <string>

#define PRICE_1 0        //房屋价格
#define PRICE_2 0		 //旅馆价格

//地产类
class Country
{
private:
	std::string name;   //地产名称
	int price;          //地产价格
	int toll;           //过路费
	int house_price;    //建筑房屋的价格
	int hotel_price;    //建筑旅馆的价格
	int house;          //房屋数
	int hotel;          //旅馆数
	int owner;          //所有者
	bool pledge;        //是否已抵押

public:
	Country();
	std::string getName() { return name; }
	int getPrice() { return price; }
	int getToll() { return toll + PRICE_1 * house + PRICE_2 * hotel; }
	int getHouse() { return house; }
	int getHotel() { return hotel; }
	int getOwner() { return owner; }
	bool getPledge() { return pledge; }

	void Build();
	void Hypothecate();
};

#endif