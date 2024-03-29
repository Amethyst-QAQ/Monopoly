#include "FateSuit.h"
#include "../IO/Output.h"

FateSuit *FateSuit::instance = new FateSuit();

void FateSuit::show()
{
	std::string mainText = "The pile have " + std::to_string(suit.size()) + "Fate cards.";
	std::string serverText = "show_Fate_cards";
	Output::instance->print(mainText, serverText);

	for (auto i = suit.begin(); i != suit.end(); i++)
		i->show();
}

void FateSuit::draw(Player* player)
{
	int luck = player->getProperty("luck");
	int n = rand() % 10;
	if (luck >= 0.5)
	{
		switch (n)
		{
		case 4:
		case 5:
			n = 3;
			break;
		case 6:
		case 7:
			n = 4;
			break;
		case 8:
		case 9:
			n = 5;
			break;
		}
		luck = luck - n * 0.1;
	}
	else
	{
		switch (n)
		{
		case 0:
		case 1:
			n = 0;
		case 6:
		case 7:
			n = 1;
		case 8:
		case 9:
			n = 2;
		}
		luck = luck + (n + 3) * 0.1;
	}
	player->setProperty("luck", luck);

	int m = rand();
	switch (n)
	{
	case 0:
		m = 0;
		break;
	case 1:
		m %= 2;
		break;
	case 2:
		m %= 3;
		break;
	case 3:
	case 4:
		m %= 8;
		break;
	case 5:
		m %= 3;
	}

	auto i = suit.begin();
	do
	{
		if (i->getVal() == n)
		{
			if (m == 0)
			{
				std::string mainText = "The Fate card been drawn is " + i->getName();
				std::string serverText = "draw_fate_card(" + i->getName() + ")";
				Output::instance->print(mainText, serverText);

				i->doEvent();

				return;
			}
			m--;
		}
		i++;
	} while (i != suit.end());
}