#ifndef PERSON_H
#define PERSON_H

#include<iostream>
#include<string>
#include"Country.h"

#define N 7 //N为颜色总数

//玩家类
class Person
{
private:
	std::string name;		//玩家昵称
	int num;				//玩家编号
	int money;				//拥有的现金数
	int country_num;		//拥有的地产数目
	int house_num;			//拥有的房屋总数
	int hotel_num;			//拥有的旅馆总数
	int power_station_num;	//拥有的发电厂数目
	int* color;				//各个颜色的地拥有的数目
	float luck;				//幸运值（影响抽卡的好坏）

public:
	Person(std::string _name, int _num) : name(_name), 
										  num(_num),
										  money(50000),
										  country_num(0), 
										  house_num(0),
										  hotel_num(0),
										  power_station_num(0),
										  luck(0) 
	{
		color = new int[N];
		for (int i = 0; i < N; i++)
			color[i] = 0;
	}
	
	std::string getName() { return name; }
	int getMoney() { return money; }
	int getCountryNumber() { return country_num; }
	int getHouseNumber() { return house_num; }
	int getHotelNumber() { return hotel_num; }
	int getPowerStationNumber() { return power_station_num; }
	int getNumber() { return num; }
	float getLuck() { return luck; }

	void setLuck(float _luck) { luck = _luck; }				//改变幸运值
	void buyCountry(Country country) { country_num++; color[country.getColor()]++; }					//购买空地
	void buyPowerStation() { power_station_num++; }			//购买发电厂
	void buildHouse() { house_num++; };						//盖房子
	void buildHotel() { hotel_num++; house_num -= 2; };		//盖旅馆
};

#endif // !PERSON_H