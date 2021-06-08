#include "FateSuit.h"

void FateSuit::show()
{
	Fate* card = nullptr;
	for (auto i = suit.begin(); i != suit.end(); i++)
	{
		*card = *i;
		card->show();
	}
}

Fate* FateSuit::draw(Player* player)
{
	Fate* card = nullptr;				//用来找卡的指针
	srand((unsigned int)time(NULL));	//根据系统时间生成随机数
	if (player->getLuck() >= 0.6 && player->getLuck() <= 1)
	{
		int n = rand() % 9;	//n表示卡的等级
		switch (n)
		{
		case 4:
		case 5:
			n = 3;			//当n = 4 or 5时，抽到的卡牌为3级
			break;
		case 6:
		case 7:
			n = 4;			//当n = 6 or 7时，抽到的卡牌为4级
			break;
		case 8:
			n = 5;			//当n = 8时，抽到的卡为5级
			break;
		default:
			break;
		}

		int m = rand();		//m表示卡的编号
		switch (n)
		{
		case 0:
			m = 0;			//等级为0的卡牌共有1张
			break;
		case 1:
			m %= 2;			//等级为1的卡牌共有2张
			break;
		case 2:
			m %= 3;			//等级为2的卡牌共有3张
			break;
		case 3:
		case 4:
			m %= 8;			//等级为3和4的卡牌共有8张
			break;
		case 5:
			m %= 3;			//等级为5的卡牌共有5张
		}

		//遍历牌库找到对应牌
		for (auto i = suit.begin(); i != suit.end(); i++)
		{
			*card = *i;
			if (card->getNum() == m && card->getVal() == n)
				return card;
		}
	}
}