#ifndef CARDS_DRAWING_FATE_SUIT_H
#define CARDS_DRAWING_FATE_SUIT_H

#include <list>
#include "Fate.h"
#include "CardsSuit.h"
#include "../Player/Player.h"

extern Player* players;

//�����ƿ�
class FateSuit : public CardsSuit
{
private:
	Fate* card;
	std::list<Fate> suit;

public:
	void show ();				//����ƿ�
	Fate* draw(int player);		//�鿨����

	void add(Fate* ChanceCard) { suit.push_back(*card); }	//���ƿ��������
};

#endif // !CARDSDRAWING_FATESUIT_H