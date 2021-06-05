#ifndef CARDSDRWING_CHANCESUIT_H
#define CARDSDRWING_CHANCESUIT_H

#include <set>
#include"Chance.h"
#include"CardsSuit.h"
#include "../Player/Person.h/"

extern Person* players;

///�����ƿ�
class ChanceSuit : public CardsSuit, public Chance
{
private:
	Chance* card;
	std::set<Chance> suit;

public:
	void show ();					//����ƿ�
	Chance* draw(int player);		//�鿨����

	void add(Chance* ChanceCard) { suit.insert(*card); }	//���ƿ��������
};

#endif // !CARDSDRWING_CHANCESUIT_H

