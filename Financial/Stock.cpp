#include"Stock.h"
#include<iostream>
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
	//srand((unsigned int)time(NULL));		//д��main��
	n = rand() % (21) - 10;                 //���� -10 �� 10 �������
	actualPrice = initialPrice * (1 + n / 100);
}

void Stock::buyStock(int player)
{
	Player& p = players[player];

	int money;
	int sum;

	string mainText = "Please choose the price you want.";
	vector<string> operation = { "In actual price(bank's)", "In player's price" };
	string serverText = "buy_stock";

	Menu menu(mainText, operation, serverText);

	int n = menu.exec();

	if (n == 1)  //In actual price
	{
		mainText = "Please enter the amount you want.\n(Attention!!! 100 �� Amount �� 1200)";   
		serverText = "buy_from_bank";

		Output::instance->print(mainText, serverText);

		n = menu.exec();
		while (n < 100 || n > 1200)
		{
			mainText = "Wrong number! Please enter again! ";
			serverText = "default_buy_from_bank";

			Output::instance->print(mainText, serverText);
			n = menu.exec();
		}
		mainText = "Successfully bought " + to_string(n) + " shares!";                      
		serverText = "success_buy_from_bank";

		Output::instance->print(mainText, serverText);


		//�����Ʊ���� ���˳��й������� Ǯ����
		sum = p.getStockNum();
		sum += n;
		p.setStockNum(n);         //�ɹ����룬���˳ֹ�������

		money = p.getMoney();
		money -= n * actualPrice;
		p.setMoney(money);        //�ɹ������֧����Ǯ����
	}
	else   //In player's price
	{

	}


}

void Stock::sellStock(int player)
{
	Player& p = players[player];

	int money;
	int sum;

	string mainText = "Please choose the selling price you want.";                                   // ʵʱ���� or �Լ�����
	vector<string> operation = { "In actual price", "In your price" };
	string serverText = "sell_price";

	Menu menu(mainText, operation, serverText);

	int n = menu.exec();

	if (n == 1) //In actual price
	{
		mainText = "Please enter the amount you want to sell.\n(Attention!!! youHave �� Amount �� 800)";
		serverText = "sell_amount";

		Output::instance->print(mainText, serverText);

		scanf("%d", &n);

		sum = p.getStockNum();//��ȡ���й���

		while (n < sum || n > 800)
		{
			mainText = "Wrong amount!\nPlease enter again!";
			serverText = "Wrong_amount";

			Output::instance->print(mainText, serverText);
			scanf("%d", &n);
		}

		mainText = "Successfully sold " + to_string(n) + " shares!";
		serverText = "Successful_sold";

		Output::instance->print(mainText, serverText);

		sum -= n;
		p.setStockNum(sum);		  //���˳ֹ�������
		money = p.getMoney();
		money += n * actualPrice;
		p.setMoney(money);		  //����Ǯ������

		soldNum[player] = n;
		soldPrice[player] = actualPrice;
	}
	else       //In your price
	{
		mainText = "Please enter the price you want.\n";//������
		serverText = "set_sell_price";

		Output::instance->print(mainText, serverText);
		scanf("%d", &n);

		while (n > 1.1 * actualPrice || n < 0.9 * actualPrice)
		{
			mainText = "Wrong Price!\nPlease enter again!";
		}


		mainText = "Please enter the amount you want.\n(Attention!!! youHave �� Amount �� 800)";
		serverText = "sell_youramount";

		Output::instance->print(mainText, serverText);

		while (n < p.getStockNum() || n>800)
		{
			mainText = "Wrong amount!\nPlease enter again!";
			serverText = "Wrong_sell_myprice_bank";

			Output::instance->print(mainText, serverText);
			n = menu.exec();
		}
		mainText = "Successfully sell " + to_string(n) + " shares!";
		serverText = "Success_sell_yourprice_bank";

		Output::instance->print(mainText, serverText);

		p.setStockNum(n);         //�����Լ��ҳ��Ĺ���

		//������Ʊ���� ���˳��й������� Ǯ����
		sum = p.getStockNum();
		sum -= n;
		p.setStockNum(sum);

		money = p.getMoney();
		p.setMoney(money);
	}


}