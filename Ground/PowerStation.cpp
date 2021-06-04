#include "PowerStation.h"

using namespace std;

void PowerStation::buy(int player)
{
	Person& p = players[player];
	int money = p.getMoney();
	if (money < price)
		cout << "You don't have enough money." << endl;
	else
	{
		cout << "Successfully bought!" << endl;
		money -= price;
		p.setMoney(money);
		p.buyPowerStation();
	}
}

void PowerStation::onStepped(int player)
{
	Person& p = players[player];

	GroundWithPrice::onStepped(player);

	if (owner != 0 && owner != player)
	{
		string name = p.getName();
		int price = getToll();

		cout << "This is " << name << "'s country." << endl;
		cout << "You have to pay " << price << "yuan as tolls." << endl;

		int money = p.getMoney();
		money -= price;
		p.setMoney(money);

		p.broke();
	}
}