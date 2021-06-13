#ifndef FINANCIAL_STOCK_H
#define FINANCIAL_STOCK_H

#include<stdlib.h>
#include "../IO/Menu.h"
#include "../IO/Output.h" 
#include "../Core/GameLogic.h"
#include "../Player/Player.h"

//股票类
class Stock
{
private:
	float initialPrice;   //开盘价
	float actualPrice;    //实时价格
	float* soldPrice;	  //玩家出售价格
	int* soldNum;		  //玩家出售数量
	int num;			  //玩家数量
public:
	Stock() : initialPrice(8), actualPrice(8), num(4)
	{
		soldPrice = new float[4]{ 0,0,0,0 };
		soldNum = new int[4]{ 0,0,0,0 };
	}
	Stock(float _initialPrice) : initialPrice(_initialPrice), actualPrice(_initialPrice), num(4)
	{
		soldPrice = new float[4]{ 0,0,0,0 };
		soldNum = new int[4]{ 0,0,0,0 };
	}
	Stock(float _initialPrice, int _num);

	void setActualPrice();

	void resetActualPrice() { initialPrice = actualPrice; }

	void buyStock(Player* player);

	void sellStock(Player* player);
};

#endif // !FINANCIAL_STOCK_H