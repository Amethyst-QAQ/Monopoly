#include "CardsSuit.h"

void CardsSuit::getLuckVal(int player, int _val)
{
	Player& p = players[player];
	int luck = p.getLuck();
	luck -= _val * 0.6;
	p.setLuck(luck);
}
