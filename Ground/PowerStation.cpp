#include "PowerStation.h"

using namespace std;

void PowerStation::buy(int player)
{
	Player& p = players[player];
	int money = p.getMoney();
	string mainText;
	string serveText;

	if (money < price)
	{
		mainText = "You don't have enough money.";
		serveText = "poor";

		Output::instance->print(mainText, serveText);
	}
	else
	{
		mainText = "Successfully bought!";
		serveText = "success";

		Output::instance->print(mainText, serveText);
		money -= price;
		p.setMoney(money);
		p.buyPowerStation();
	}
}

void PowerStation::onStepped(int player)
{
	Player& p = players[player];

	if (owner != 0 && owner != player)
	{
		string name = p.getName();
		int price = getToll(owner);

		cout << "This is " << name << "'s country." << endl;
		cout << "You have to pay " << price << "yuan as tolls." << endl;

		int money = p.getMoney();
		money -= price;
		p.setMoney(money);
	}

	GroundWithPrice::onStepped(player);
}

int PowerStation::getToll(int player)
{
	return players[player].getPowerStationNumber() * toll;
}
