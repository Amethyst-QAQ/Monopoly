#ifndef CARDS_DRAWING_FATE_SUIT_H
#define CARDS_DRAWING_FATE_SUIT_H

#include <set>
#include "Fate.h"
#include "CardsSuit.h"
#include "../Player/Person.h/"

extern Person* players;

//�����ƿ�
class FateSuit : public CardsSuit, public Fate
{
private:
	Fate* card;
	std::set<Fate> suit;

public:
	void show ();				//����ƿ�
	Fate* draw(int player);		//�鿨����

	void add(Fate* ChanceCard) { suit.insert(*card); }	//���ƿ��������
};

#endif // !CARDSDRAWING_FATESUIT_H