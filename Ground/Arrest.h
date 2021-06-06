#ifndef GROUND_ARREST_H
#define GROUND_ARREST_H

#include "Prison.h"
#include "Ground.h"
#include "../Player/Player.h"

///ШыгќИёзг
class Arrest : public Ground
{
public:
	void onStepped(Player& a, Prison* b)
	{ 
		a.setPosition(b); 
		b->beArrest(a); 
	}
};

#endif