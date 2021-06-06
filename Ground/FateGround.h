#ifndef GROUND_FATEGROUND_H
#define GROUND_FATEGROUND_H
#include"Ground.h"

#include "Ground.h"
#include "../CardsDrawing/FateSuit.h"

extern FateSuit pile;

///命运格子类
///机会格子类
class FateGround : public Ground, FateSuit
{
	void onStepped(int player);
};

#endif // !FATEGROUND_H

