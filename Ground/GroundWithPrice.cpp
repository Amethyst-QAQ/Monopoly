#include "GroundWithPrice.h"
#include "../Player/Person.h"

using namespace std;

void GroundWithPrice::onStepped(int player)
{
	Ground::onStepped(player);
	if (owner == 0)
	{
		string mainText = "The ground hasn't been sold.";
		vector<string> operation = { "Buy", "Exit" };
		string serverText = "buy_ground";

		Menu menu(mainText, operation, serverText);

		int n = menu.exec();

		switch (n)
		{
		case 1:
			buy(player);
			setOwner(player);
			break;
		case 2:
			return;
		}
	}
}
