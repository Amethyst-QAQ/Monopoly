#ifndef GROUND_FATEGROUND_H
#define GROUND_FATEGROUND_H
#include"Ground.h"

#include "Ground.h"
#include "../CardsDrawing/FateSuit.h"

///���˸�����
class FateGround : public Ground, FateSuit
{
public:
	void onStepped();
};
#endif // !FATEGROUND_H

