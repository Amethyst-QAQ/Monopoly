#include "GroundWithPrice.h"
#include "../IO/Menu.h"
#include "../IO/Output.h"
#include "../Player/Player.h"

using namespace std;

void GroundWithPrice::buy(Player *player)
{
	int money = player->getMoney();
	if (money < price)
	{
		Output::instance->print(
			"You don't have enough money to buy this ground.",
			"insufficient_money"
		);
		return;
	}
	money -= price;
	player->setMoney(money);
	setOwner(player);
	Output::instance->print(
		"Successfully bought!",
		"success"
	);
}

void GroundWithPrice::redeem(Player *player)
{
	int money = player->getMoney();
	if (money < price)
	{
		Output::instance->print(
			"You don't have enough money to redeem this ground.",
			"insufficient_money"
		);
		return;
	}
	money -= price;
	player->setMoney(money);
	setPledge(false);
}

void GroundWithPrice::onStepped(Player *player)
{
	Ground::onStepped(player);

	if (owner == 0)
	{
		string mainText = "The ground hasn't been sold.";
		vector<string> operation = { "Buy at price " + to_string(price), "Exit" };
		string serverText = "buy_ground";

		Menu menu(mainText, operation, serverText);

		int n = menu.exec();

		switch (n)
		{
		case 1:
			buy(player);
			break;
		case 2:
			return;
		}
	}

	if (owner == player && pledge)
	{
		string mainText = "The ground is mortgaged.";
		vector<string> operations = { "Redeem at price " + to_string(price), "Exit" };
		string serverText = "redeem_ground";
		Menu menu(mainText, operations, serverText);

		int n = menu.exec();

		switch (n)
		{
		case 1:
			redeem(player);
			break;
		case 2:
			return;
		}
	}

	if (owner != player)
	{
		Output::instance->print(
			"The ground belongs to " + owner->getName() + ". You have to pay " + to_string(getToll()),
			"pay_toll(" + owner->getName() + ")(" + to_string(getToll()) + ")"
		);
		player->setMoney(player->getMoney() - getToll());
	}
}
