#ifndef CARDS_DRAWING_CHANCE_SUIT_CHANCE_1_H
#define CARDS_DRAWING_CHANCE_SUIT_CHANCE_1_H

#include "../Chance.h"
#include"../../Player/Player.h"

class Chance_1 :public Chance
{
public:
	Chance_1() :Chance("ɨ���ж�", 0, 0) {}     //���캯������ʼ��Chance_1�����¼����ơ�����ֵ�����
	void doEvent(Player* player) { player->setMoney(player->getMoney() - 2000); }
};

#endif // ! CHANCE_1_H
