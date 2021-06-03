#ifndef COUNTRY_H
#define COUNTRY_H

#include <iostream>
#include <string>
#include "Ground.h"

#define PRICE_1 0        //房屋价格
#define PRICE_2 0		 //旅馆价格

//地产类，继承格子类
class Country : public Ground
{
private:
	std::string name;   //地产名称
	int price;          //地产价格
	int toll;           //过路费
	int house_price;    //建筑房屋的价格
	int hotel_price;    //建筑旅馆的价格
	int house;          //房屋数，上限两个
	int hotel;          //旅馆数，上限两个
	int owner;          //所有者，0代表银行
	int color;			//颜色（拥有同色的所有国家地区就加收过路费为原来的3倍）
	bool pledge;        //是否已抵押

public:
	Country(std::string _name, int _price, int _toll, int _owner, int color, int _house_price, int _hotel_price);

	void setName(std::string _name) { name = _name; }
	void setPrice(int _price) { price = _price; }
	void setToll(int _toll) { toll = _toll; }
	void setOwner(int _owner) { owner = _owner; } //相当于购买函数；路过时直接检测owner是不是0即可
	void setColor(int _color) { color = _color; }
	void setHousePrice(int _house_price) { house_price = _house_price; }
	void setHotelPrice(int _hotel_price) { hotel_price = _hotel_price; }

	std::string getName() { return name; }
	int getPrice() { return price; }
	int getToll() { return toll + PRICE_1 * house + PRICE_2 * hotel; }
	int getHouse() { return house; }
	int getHotel() { return hotel; }
	int getOwner() { return owner; }
	bool getPledge() { return pledge; }
	int getColor() { return color; }

	void HouseBuild();	//建造房屋
	void HotelBuild();	//建造旅馆
	void Hypothecate();	//抵押房屋
};

#endif