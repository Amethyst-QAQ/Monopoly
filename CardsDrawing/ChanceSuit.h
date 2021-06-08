#ifndef CARDS_DRWING_CHANCE_SUIT_H
#define CARDS_DRWING_CHANCE_SUIT_H

#include <list>
#include"Chance.h"
#include"CardsSuit.h"
#include "../Player/Player.h"

/**
* @brief �����ƿ��࣬���ڻ�����ӳ鿨������ƿ���Ϣ
* draw()�������ڳ鿨�����Ը�����ҵ�����ֵ�����Զ��鿨��ִ����ز���
* show()������������ƿ��к��е�������ÿ���Ƶ���Ϣ
* add()�����������ƿ��������
*/

class ChanceSuit : public CardsSuit
{
private:
	std::list<Chance> suit;
public:
	static Output* instance;

	void show ();						
	void draw(Player* player);
	void add(Chance* ChanceCard) { suit.push_back(*ChanceCard); }
};

#endif // !CARDSDRWING_CHANCESUIT_H