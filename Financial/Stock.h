#ifndef STOCK_H
#define STOCK_H

#include<ctime>
#include<stdlib.h>
#include "../Player/Menu.h"
#include "../Player/Output.h"
#include "../Player/Player.h"
extern Player* players;

using namespace std;


//��Ʊ��
class Stock
{
private:
	float initialPrice;   //���̼�
	float actualPrice;    //ʵʱ�۸�
public:
	Stock();

	void setActualPrice();

	void resetActualPrice();

	void buyStock(int player);
	
	void sellStock(int player);

};

#endif // !STOCK_H

