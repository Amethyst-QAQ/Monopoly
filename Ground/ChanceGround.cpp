#include"ChanceGround.h"
using namespace std;

void ChanceGround::onStepped(int player)
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
