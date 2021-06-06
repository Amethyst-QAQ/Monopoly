#ifndef GROUND_CHANCEGROUND_H
#define GROUND_CHANCEGROUND_H

#include "Ground.h"
#include "../CardsDrawing/ChanceSuit.h"
#include "../Player/Output.h"
#include "../Player/Menu.h"

using namespace std;

extern ChanceSuit pile;

///机会格子类
class ChanceGround : public Ground, ChanceSuit
{
	void onStepped(int player)
	{
		Player& p = players[player];
		Chance* luckyCard;
		string mainText;
		string serveText;

		mainText = "Please draw a card from ChanceSuit.";
		serveText = "draw_chancecard";

		Output::instance->print(mainText, serveText);
		luckyCard = pile.draw(player);
		luckyCard->doEvent();
	}
};
#endif // !CHANCEGROUND_H

