#ifndef PLAYER_PERSON_H
#define PLAYER_PERSON_H

#include <iostream>
#include <string>
#include "../Ground/Country.h"
#include "../Ground/Ground.h"
#include "../Ground/PowerStation.h"

#define N 7 //N为颜色总数

//玩家类
class Person
{
private:
	std::string name;		//玩家昵称
	int num;				//玩家编号
	int money;				//拥有的现金数
	int countryNum;			//拥有的地产数目
	int powerStationNum;	//拥有的发电厂数目
	int* colorCountryNum;	//各个颜色的地拥有的数目
	float luck;				//幸运值（影响抽卡的好坏）
	int pause;				//暂停回合数
	Ground* position;		//指向玩家现在所在位置

public:
	Person(std::string _name, int _num) : name(_name), 
										  num(_num),
										  money(50000),
										  countryNum(0), 
										  powerStationNum(0),
										  luck(0),
										  pause(0),
										  position(nullptr)
	{
		colorCountryNum = new int[N];
		for (int i = 0; i < N; i++)
			colorCountryNum[i] = 0;
	}
	
	std::string getName() { return name; }
	int getMoney() { return money; }
	int getCountryNumber() { return countryNum; }
	int getPowerStationNumber() { return powerStationNum; }
	int getNumber() { return num; }
	float getLuck() { return luck; }
	int getPause() { return pause; }
	Ground* getPosition() { return position; }

	void setPosition(Ground* ground) { position = ground; }	//改变玩家位置
	void setPause(int num) { pause = num; }					//被暂停num回合
	void setLuck(float _luck) { luck = _luck; }				//改变幸运值
	void setHotel(int num) { hotel_num = num; }             //改变旅馆数
	void buyCountry(Country country) { country_num++; color[country.getColor()]++; }					//购买空地
	void buyPowerStation() { power_station_num++; }			//购买发电厂
	void buildHouse() { house_num++; };						//盖房子
	void buildHotel() { hotel_num++; house_num -= 2; };		//盖旅馆
};

#endif // !PERSON_H