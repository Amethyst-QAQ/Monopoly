#ifndef PLAYER_DICE_H
#define PLAYER_DICE_H

#include <cstdlib>

class Dice
{
private:
	int num;
public:
	int getNum() { num = (std::rand() % 6) + 1; return num; }
};

#endif