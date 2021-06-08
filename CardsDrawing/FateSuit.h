#ifndef CARDS_DRAWING_FATE_SUIT_H
#define CARDS_DRAWING_FATE_SUIT_H

#include <list>
#include "Fate.h"
#include "CardsSuit.h"
#include "../Player/Player.h"

/**
* @brief �����ƿ��࣬�������˸��ӳ鿨������ƿ���Ϣ
* draw()�������ڳ鿨�����Ը�����ҵ�����ֵ�����Զ��鿨��ִ����ز���
* show()������������ƿ��к��е�������ÿ���Ƶ���Ϣ
* add()�����������ƿ��������
*/

class FateSuit : public CardsSuit
{
private:
	std::list<Fate> suit;

public:
	static Output* instance;
	void show ();
	void draw(Player* player);
	void add(Fate* ChanceCard) { suit.push_back(*ChanceCard); }
};

#endif // !CARDSDRAWING_FATESUIT_H