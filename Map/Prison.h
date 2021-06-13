#ifndef PRISON_H
#define PRISON_H

#include "Ground.h"
#include "../Player/Player.h"

class Player;

class Prison : public Ground
{
public:
	Prison() : Ground("Prison") {}
};

#endif