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

void Stock::buyStock(int player)
{
	Player& p = players[player];
	
	string str;
	float price = 0;					//记录价格
	int sum = 0;					//记录数量
	int s = 0;					//计数器
	int* choice = new int[num];	//记录玩家所对应选项

	for (int i = 0;i < num;i++)
		choice[i] = 0;

	string mainText = "Please choose the price you want.";
	vector<string> operation = { "In actual price(bank's)", "In player's price" };
	string serverText = "buy_stock";

	Menu menu(mainText, operation, serverText);

	int n = menu.exec();
	if (n == 1)  //In actual price
	{
		mainText = "Please enter the amount you want.\n(Attention!!! 100 ≤ Amount ≤ 1200)";   
		serverText = "buy_from_bank";

		operation = {};

		Menu menu1(mainText, operation, serverText);
		sum = menu1.exec();
		while (sum % 100 != 0)
		{
			mainText = "Wrong amount! \nPlease enter again! ";
			serverText = "wrong_amount";

			operation = {};

			Menu menu2(mainText, operation, serverText);
			sum = menu2.exec();
		}

		mainText = "Successfully bought " + to_string(n) + " shares!";                      
		serverText = "success_buy_from_bank";

		Output::instance->print(mainText, serverText);

		p.buyStock(sum, actualPrice);
	}

	else   //In player's price
	{	
		mainText = "Please choose the price you want.";
		serverText = "buy_from_player";
		operation = {};

		for (int i = 0;i < num;i++)	
			if (soldPrice[i] != 0)
			{
				choice[i] = s;
				s++;
				str = to_string(soldPrice[i]) + "Maxium: " + to_string(soldNum[i]) + "shares)";
				operation.push_back(str);
			}

		operation.push_back("return to previous menu");

		Menu menu3(mainText, operation, serverText);
		n = menu3.exec();//储存选项

		for (int i = 0;i < num;i++)
		{
			if (n == choice[i])
			{
				price = soldPrice[i];
				n = i;//记录选项
				break;
			}
		}
		mainText = "Please input the amount you want.";
		serverText = "amount_from_player";
		operation = {};
		Menu menu4(mainText, operation, serverText);
		sum = menu4.exec();

		while(sum > soldNum[n] || sum % 100 != 0 || sum <= 0)
		{
			mainText = "Wrong amount! \nPlease enter again! ";
			serverText = "wrong_amount";

			operation = {};

			Menu menu(mainText, operation, serverText);
			sum = menu.exec();
		}

		mainText = "Successfully bought " + to_string(sum) + " shares!";
		serverText = "success_buy_from_bank";

		Output::instance->print(mainText, serverText);

		p.buyStock(sum, price);
		players[n].sellStock(sum, price);
	}
}

void Stock::sellStock(int player)
{
	Player& p = players[player];

	float price = 0;
	int sum = 0;
	int amount = 0;

	sum = p.getStockNum();//获取现有股数

	string mainText = "Please choose the selling price you want.";                                   // 实时定价 or 自己定价
	vector<string> operation = { "In actual price", "In your price" };
	string serverText = "sell_price";

	Menu menu(mainText, operation, serverText);

	int n = menu.exec();

	if (n == 1) //In actual price
	{
		mainText = "Please enter the amount you want to sell.\n(Attention!!! youHave ≤ Amount ≤ 800)";
		serverText = "sell_amount";
		operation = {};

		Menu menu1(mainText, operation, serverText);
		n = menu1.exec();

		while (n < sum || n > 800)
		{
			mainText = "Wrong amount!\nPlease enter again!";
			serverText = "Wrong_amount";
			operation = {};

			Menu menu2(mainText, operation, serverText);
			n = menu2.exec();
		}

		mainText = "Successfully sold " + to_string(n) + " shares!";
		serverText = "Successful_sold";

		Output::instance->print(mainText, serverText);

		soldNum[player] = n;
		soldPrice[player] = actualPrice;
	}

	else       //In your price
	{
		mainText = "Please enter the price you want.\n";//有问题
		serverText = "sell_price";
		operation = {};

		Menu menu3(mainText, operation, serverText);
		n = menu3.exec();

		while (n > 1.1 * actualPrice || n < 0.9 * actualPrice)
		{
			mainText = "Wrong Price!\nPlease enter again!";
			serverText = "wrong_price";
			operation = {};

			Menu menu(mainText, operation, serverText);
			n = menu.exec();
		}

		price = n;
		amount = 800 + (actualPrice - amount) * 50;	//有待数学模型的建立
		
		mainText = "Please enter the amount you want.\n(Attention!!! youHave ≤ Amount ≤ 800)";
		serverText = "sell_amount";
		operation = {};

		Menu menu4(mainText, operation, serverText);
		n = menu4.exec();

		while (n < sum || n > amount)
		{
			mainText = "Wrong amount!\nPlease enter again!";
			serverText = "Wrong_amount";
			operation = {};

			Menu menu5(mainText, operation, serverText);
			n = menu5.exec();
		}
		mainText = "Successfully input " + to_string(n) + " shares to sell.";
		serverText = "Success_intput_amount";

		Output::instance->print(mainText, serverText);

		soldNum[player] = n;
		soldPrice[player] = price;
	}
}