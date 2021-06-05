#ifndef GROUND_CHANCEGROUND_H
#define GROUND_CHANCEGROUND_H
#include"Ground.h"

#include "Ground.h"
#include "../CardsDrawing/CardsDrawing.h"
#include "../CardsDrawing/CardsSuit.h"

///命运格子类
class ChanceGround : public Ground
{
private:
	CardsDrawing m_CardsDrawing;
	ChanceSuit m_ChanceSuit;
public:
	void onstepped(Person &a)
	{
		m_CardsDrawing.Draw(a);
		if (m_ChanceSuit.Chance::getVal() == m_CardsDrawing.getVal())
		{
			if (m_ChanceSuit.Chance::getNum() == m_CardsDrawing.getNum())
			{

			}
		}
		m_CardsDrawing.LuckVal(a);          //更新玩家幸运值
		
	}
};
#endif // !CHANCEGROUND_H

