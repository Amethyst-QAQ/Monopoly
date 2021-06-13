#ifndef MAP_BONUS_GROUND_H
#define MAP_BONUS_GROUND_H

#include "Ground.h"
#include "../Player/Player.h"

class BonusGround : public Ground
{
private:
	int bonus;
public:
	BonusGround(const std::string &name, int _bonus) : Ground(name), bonus(_bonus) {}
	virtual bool onStepped(Player* player);

	virtual void show();
};

#endif // !MAP_TAX_H
