#include"FateGround.h"
using namespace std;

///命运格子类

void FateGround::onStepped(int player)
{
	Player& p = players[player];
	Fate* luckyCard;
	string mainText;
	string serveText;

	mainText = "Please draw a card from ChanceSuit.";
	serveText = "draw_chancecard";

	Output::instance->print(mainText, serveText);
	luckyCard = pile.draw(player);
	luckyCard->doEvent();
}

