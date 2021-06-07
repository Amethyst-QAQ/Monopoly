#ifndef PLAYER_PERSON_H
#define PLAYER_PERSON_H

#include <string>
#include <iostream>
#include "Menu.h"
#include "../Player/Output.h"
#include "../Ground/Ground.h"

#define N 7 //N为颜色总数

///玩家类
class Player
{
private:
	std::string name;		//玩家昵称
	int money;				//拥有的现金数
	int countryNum;			//拥有的地产数目
	int powerStationNum;	//拥有的发电厂数目
	int* colorCountryNum;	//各个颜色的地拥有的数目
	float luck;				//幸运值（影响抽卡的好坏）
	int pause;				//暂停回合数
	float myStockPrice;     //个人出售股票定价
	int stockNum;           //个人持有股数
	int sellNum;            //个人挂出的股数
	Ground* position;		//指向玩家现在所在位置

public:
	Player(std::string _name) : name(_name),
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
	Player() : name("nmae"),
		money(50000000),
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
	float getLuck() { return luck; }
	int getPause() { return pause; }
	int getStockNum() { return stockNum; }
	float getmyStockPrice() { return myStockPrice; }
	int getsellellkNum() { return sellNum; }
	Ground* getPosition() { return position; }

	void setMoney(int _money);
	void setPosition(Ground* ground) { position = ground; }			//改变玩家位置
	void changePause(int num) { pause = pause + num; }				//被暂停num回合
	void setLuck(float _luck) { luck = _luck; }						//改变幸运值
	void setStockNum(int num) { stockNum = num; }                   //输入现持股数
	void setmyStockPrice(float price) { myStockPrice = price; }     //输入个人股票定价
	void setSellNum(int num) { sellNum = num; }                     //输入个人挂出的股数

	void buyCountry();		//购买空地
	void buyPowerStation();	//购买发电厂

	void bePaused() { pause--; };
	void show();
	void broke();			//破产
};

#endif // !PERSON_H