#ifndef GROUND_FATEGROUND_H
#define GROUND_FATEGROUND_H
#include"Ground.h"

#include "Ground.h"
#include "../CardsDrawing/FateSuit.h"

extern FateSuit pile;

///���˸�����
///���������
class FateGround : public Ground, FateSuit
{
	void onStepped(int player);
};

#endif // !FATEGROUND_H

