#include "BonusGround.h"
#include "../IO/Output.h"

using namespace std;

bool BonusGround::onStepped(Player* player)
{
	if (Ground::onStepped(player))
		return true;
	player->setMoney(player->getMoney() + bonus);
	return true;
}

void BonusGround::show()
{
	Ground::show();
	string mainText;
	string serverText;

	mainText = "Bonus: " + to_string(bonus);
	serverText = "show_bonus (" + to_string(bonus) + ")";
	Output::instance->print(mainText, serverText);
}
