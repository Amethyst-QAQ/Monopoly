#ifndef STOCK_H
#define STOCK_H

#include<ctime>
#include<stdlib.h>
#include "../Player/Menu.h"
#include "../Player/Output.h"
#include "../Player/Player.h"
extern Player* players;

using namespace std;


//股票类
class Stock
{
private:
	float initialPrice;   //开盘价
	float actualPrice;    //实时价格
public:
	Stock();

	void setActualPrice();

	void resetActualPrice();

	void buyStock(int player);
	
	void sellStock(int player);

};

#endif // !STOCK_H

