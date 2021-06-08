#include "GroundWithPrice.h"
#include "../IO/Menu.h"
#include "../IO/Output.h"
#include "../Player/Player.h"

using namespace std;

void GroundWithPrice::show()
{
	string mainText;
	string serverText;

	mainText = "Name: " + getName();
	serverText = "show_name " + getName();
	Output::instance->print(mainText, serverText);

	mainText = "Price: " + to_string(price);
	serverText = "show_price " + getName();
	Output::instance->print(mainText, serverText);

	mainText = "Owner: " + owner->getName();
	serverText = "show_owner " + getName();
	Output::instance->print(mainText, serverText);

	mainText = "Pledge: " + to_string(pledge);
	serverText = "show_pledge " + getName();
	Output::instance->print(mainText, serverText);
}

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

bool GroundWithPrice::onStepped(Player *player)
{
	if(Ground::onStepped(player))
		return true;

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
			return true;
		case 2:
			return true;
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
			return true;
		case 2:
			return true;
		}
	}

	if (owner != player)
	{
		Output::instance->print(
			"The ground belongs to " + owner->getName() + ". You have to pay " + to_string(getToll()),
			"pay_toll(" + owner->getName() + ")(" + to_string(getToll()) + ")"
		);
		player->setMoney(player->getMoney() - getToll());
		return true;
	}

	return false;
}
