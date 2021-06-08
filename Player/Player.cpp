#include "Player.h"

#include "../IO/Menu.h"
#include "../IO/Output.h"
#include "../Map/Map.h"
#include "../Map/GroundWithPrice.h"

using namespace std;

int Player::getProperty(const std::string &name)
{
	auto iter = properties.find(name);
	if (iter != properties.end())
		return (*iter).second;
	return 0;
}

void Player::broke()
{
	int size = Map::instance->getSize();

	vector<GroundWithPrice *> grounds;

	for (int i = 0; i < size; i++)
	{
		GroundWithPrice *temp = dynamic_cast<GroundWithPrice *>(Map::instance->getGround(i));
		if (temp && temp->getOwner() == this)
			grounds.push_back(temp);
	}

	int priceSum = 0;

	for (GroundWithPrice *i : grounds)
		priceSum += i->getPrice() / 2;

	if (priceSum + money < 0)
	{
		Output::instance->print(
			"Player " + name + "Failed.",
			"fail(" + name + ")"
		);

		for (GroundWithPrice *i : grounds)
			i->setOwner(nullptr);

		setProperty("failed", 1);
		return;
	}

	while (money < 0)
	{
		string mainText = "Your money isn't enough.PLease choose a ground to pledge.";
		vector<string> operation;
		string serverText = "";
		GroundWithPrice* temp;

		for(int i = 0;i < grounds.size();i++)
		{
			temp = grounds[i];
			operation.push_back(getName() + "(The  price is: " + to_string(temp->getPrice()) + " yuan)");
			serverText = serverText + to_string(i) + "\n";
		}

		Menu menu(mainText, operation, serverText);
		int n = menu.exec();

		bool pledge = true;
		grounds[n - 1]->setPledge(pledge);

		mainText = "You have successfully pledged the country.";
		serverText = "successful_pledged";
		Output::instance->print(mainText, serverText);
	}
}
