#ifndef CARDS_DRWING_CHANCE_SUIT_H
#define CARDS_DRWING_CHANCE_SUIT_H

#include <list>
#include"Chance.h"
#include"CardsSuit.h"
#include "../Player/Player.h"

///�����ƿ�
class ChanceSuit : public CardsSuit
{
private:
	std::list<Chance> suit;

public:
	static Output* instance;

	void show ();						//����ƿ�
	Chance* draw(Player* player);		//�鿨����
	void add(Chance* ChanceCard) { suit.push_back(*ChanceCard); }	//���ƿ��������
};

#endif // !CARDSDRWING_CHANCESUIT_H