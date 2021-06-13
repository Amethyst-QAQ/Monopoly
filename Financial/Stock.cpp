#include"Stock.h"

using namespace std;

Stock::Stock(float _initialPrice, int _num) : initialPrice(_initialPrice),
actualPrice(_initialPrice),
num(_num)
{
	soldPrice = new float[_num];
	soldNum = new int[_num];
	for (int i = 0;i < num;i++)
	{
		soldPrice[i] = 0;
		soldNum[i] = 0;
	}
}

void Stock::setActualPrice()
{
	int n;
	//srand((unsigned int)time(NULL));		//写在main里
	n = rand() % (21) - 10;                 //生成 -10 到 10 的随机数
	actualPrice = initialPrice * (1 + n / 100);
}

void Stock::buyStock(Player* player)
{
	int money;
	int sum;
	int num;

	string mainText = "Please choose the price you want.";
	vector<string> operation = { "In actual price(bank's)", "In player's price" };
	string serverText = "buy_stock";

	Menu menu(mainText, operation, serverText);

	int n = menu.exec();

	if (n == 1)  //In actual price
	{
		mainText = "Please enter the amount you want.\n(Attention!!! 100 ≤ Amount ≤ 1200)";
		serverText = "buy_from_bank";
		vector<string> operation = {};

		Menu menu1(mainText, operation, serverText);
		n = menu.exec();

		while (n < 100 || n > 1200)
		{
			mainText = "Wrong number! Please enter again! ";
			serverText = "default_buy_from_bank";
			vector<string> operation = {};

			Menu menu2(mainText, operation, serverText);
			n = menu2.exec();
		}
		mainText = "Successfully bought " + to_string(n) + " shares!";
		serverText = "success_buy_from_bank";

		Output::instance->print(mainText, serverText);

		sum = player->getProperty("StockNum");
		sum += n;
		player->setProperty("StockNum",n);

		money = player->getMoney();
		money -= n * actualPrice;
		player->setMoney(money); 
	}
	else
	{

	}
}

void Stock::sellStock(Player* player)
{
	int money;
	int sum;
	int num = player->getNum();

	string mainText = "Please choose the selling price you want.";                                   // 实时定价 or 自己定价
	vector<string> operation = { "In actual price", "In your price" };
	string serverText = "sell_price";

	Menu menu(mainText, operation, serverText);

	int n = menu.exec();

	if (n == 1) //In actual price
	{
		mainText = "Please enter the amount you want to sell.\n(Attention!!! youHave ≤ Amount ≤ 800)";
		serverText = "sell_amount";

		Output::instance->print(mainText, serverText);

		sum = player->getProperty("Stock");//获取现有股数

		while (n < sum || n > 800)
		{
			mainText = "Wrong amount!\nPlease enter again!";
			serverText = "Wrong_amount";
			vector<string> operation = {};

			Menu menu1(mainText, operation, serverText);
			n = menu1.exec();
		}

		mainText = "Successfully sold " + to_string(n) + " shares!";
		serverText = "Successful_sold";

		Output::instance->print(mainText, serverText);

		sum -= n;
		player->setProperty("StockNum",sum);		  //个人持股数减少
		money = player->getMoney();
		money += n * actualPrice;
		player->setMoney(money);		  //个人钱数增加

		soldNum[num] = n;
		soldPrice[num] = actualPrice;
	}
	else       //In your price
	{
		mainText = "Please enter the price you want.\n";//有问题
		serverText = "set_sell_price";
		vector<string> operation = {};

		Menu menu2(mainText, operation, serverText);
		n = menu2.exec();

		while (n > 1.1 * actualPrice || n < 0.9 * actualPrice)
		{
			mainText = "Wrong Price!\nPlease enter again!";
			vector<string> operation = {};

			Menu menu(mainText, operation, serverText);
			n = menu.exec();
		}

		mainText = "Please enter the amount you want.\n(Attention!!! youHave ≤ Amount ≤ 800)";
		serverText = "sell_youramount";
		vector<string> operation2 = {};

		Menu menu3(mainText, operation, serverText);
		n = menu3.exec();

		while (n < player->getProperty("Stock") || n > 800)
		{
			mainText = "Wrong amount!\nPlease enter again!";
			serverText = "Wrong_sell_myprice_bank";

			Output::instance->print(mainText, serverText);
			n = menu.exec();
		}

		mainText = "Successfully sell " + to_string(n) + " shares!";
		serverText = "Success_sell_yourprice_bank";

		Output::instance->print(mainText, serverText);

		player->setProperty("StockNum",n);
		sum = player->getProperty("Stock");
		sum -= n;
		player->setProperty("StockNum", n);

		money = player->getMoney();
		player->setMoney(money);
	}
}