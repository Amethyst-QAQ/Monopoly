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
	float myPrice;        //个人出售定价
	int num;              //个人持有股数
public:
	Stock()
	{
		initialPrice = 8;
		actualPrice = 0;
		myPrice = 0;
		num = 0;
	}
	void setActualPrice()
	{
		int n;
		srand((unsigned int)time(NULL));
		n = rand() % (21) - 10;                 //生成 -10 到 10 的随机数
		actualPrice = initialPrice * (1 + n / 100);
	}

	void resetActualPrice()
	{
		initialPrice = actualPrice;
	}

	void buyStock(int player)
	{
		Player& p = players[player];

		int money;  

		string mainText = "Please choose the buying way you want.";
		vector<string> operation = { "From bank", "From player" };
		string serverText = "buy_stock";

		Menu menu(mainText, operation, serverText);

		int n = menu.exec();

		switch (n)
		{
		case 1:
			mainText = "Please enter the amount you want.\n(Attention!!! 100 ≤ Amount 1200)";
			serverText = "buy_from_bank";

			Output::instance->print(mainText, serverText);

			n = menu.exec();
			while (n < 100 || n>1200)
			{
				mainText = "Wrong number! Please enter again! ";  //成功买入n股
				serverText = "default_buy_from_bank";

				Output::instance->print(mainText, serverText);
				n = menu.exec();
			}
			mainText = "Successfully bought " + to_string(n) + " shares";  //成功买入n股
			serverText = "success_buy_from_bank";

			Output::instance->print(mainText, serverText);

			myPrice += n;                                            //成功买入，个人持股数增加
			money = p.getMoney();
			money -= n * actualPrice;
			p.setMoney(money);

		case 2:

		default:
			break;
		}
	}

};

#endif // !STOCK_H

