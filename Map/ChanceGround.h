#ifndef GROUND_CHANCEGROUND_H
#define GROUND_CHANCEGROUND_H

#include "Ground.h"
#include "../CardsDrawing/ChanceSuit.h"
#include "../Player/Output.h"
#include "../Player/Menu.h"

using namespace std;

extern ChanceSuit pile_1;

///机会格子类
class ChanceGround : public Ground
{
	void onStepped(int player);
};
#endif // !CHANCEGROUND_H