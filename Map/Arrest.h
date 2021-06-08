#ifndef GROUND_ARREST_H
#define GROUND_ARREST_H

#include "Prison.h"
#include "Ground.h"
#include "../Player/Output.h"
#include "../Player/Player.h"

extern Player* players;

///ШыгќИёзг
class Arrest : public Ground
{
private:
	Prison* prison;
public:
	Arrest(Prison* _prison) : prison(_prison) {}
	void onStepped(int player);
};

#endif