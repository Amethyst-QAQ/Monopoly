#include "ChanceSuit.h"
#include "../IO/Output.h"

ChanceSuit *ChanceSuit::instance = new ChanceSuit();

void ChanceSuit::show()
{
	Chance* card = nullptr;
	std::string mainText = "The pile have " + std::to_string(suit.size()) + "Chance cards.";
	std::string serverText = "show_Chance_cards";
	Output::instance->print(mainText, serverText);

	for (auto i = suit.begin(); i != suit.end(); i++)
	{
		*card = *i;
		card->show();
		printf("\n");
	}
}

void ChanceSuit::draw(Player *player)
{
	int luck = player->getProperty("luck");
	int n = rand() % 10;
	if (luck >= 0.5)
	{
		switch (n)
		{
		case 4:
		case 5:
			n = 3;			//��n = 4 or 5ʱ���鵽�Ŀ���Ϊ3��
			break;
		case 6:
		case 7:
			n = 4;			//��n = 6 or 7ʱ���鵽�Ŀ���Ϊ4��
			break;
		case 8:
		case 9:
			n = 5;			//��n = 8 or 9ʱ���鵽�Ŀ�Ϊ5��
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
			m = 0;			//�ȼ�Ϊ0�Ŀ��ƹ���1��
			break;
		case 1:
			m %= 2;			//�ȼ�Ϊ1�Ŀ��ƹ���2��
			break;
		case 2:
			m %= 3;			//�ȼ�Ϊ2�Ŀ��ƹ���3��
			break;
		case 3:
		case 4:
			m %= 8;			//�ȼ�Ϊ3��4�Ŀ��ƹ���8��
			break;
		case 5:
			m %= 3;			//�ȼ�Ϊ5�Ŀ��ƹ���5��
		}

	auto i = suit.begin();
	do
	{
		if (i->getVal() == n)
		{
			if (m == 0)
			{
				std::string mainText = "The Chance card been drawn is " + i->getName();
				std::string serverText = "draw_Chance_card " + i->getName();
				Output::instance->print(mainText, serverText);

				i->doEvent();

				return;
			}
			m--;
		}
		i++;
	} while (i != suit.end());
}
