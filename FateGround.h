#ifndef FATEGROUND_H
#define FATEGROUND_H

#include "Ground.h"
#include "CardsDrawing.h"

//命运格子类
class FateGround : public Ground
{
public:
	void onStepped();
};
#endif // !FATEGROUND_H

