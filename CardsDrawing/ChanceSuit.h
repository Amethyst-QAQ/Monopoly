#ifndef CARDS_DRWING_CHANCE_SUIT_H
#define CARDS_DRWING_CHANCE_SUIT_H

#include <list>
#include"Chance.h"
#include"CardsSuit.h"
#include "../Player/Player.h"

extern Player* players;

///�����ƿ�
class ChanceSuit : public CardsSuit, public Chance
{
private:
	std::set<Chance> suit;
	Chance* card;
	std::list<Chance> suit;

public:
	void show ();					//����ƿ�
	Chance* draw(int player);		//�鿨����

	void add(Chance* ChanceCard) { suit.push_back(*card); }	//���ƿ��������
};

#endif // !CARDSDRWING_CHANCESUIT_H

