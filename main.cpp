#include "Player/Player.h"
#include "Player/Output.h"
#include "Player/Dice.h"
#include "Player/Menu.h"
#include "Ground/InitGrounds.h"

bool isServer = false;
Player *players = nullptr;

using namespace std;

int main(int argc, char** argv)
{
	if (argc == 2 && argv[1] == string("server"))
		isServer = true;

	srand((unsigned int)time(NULL));

	vector<Ground*> mapVector;

	mapVector.push_back(new Beginning);
	Prison* prison = new Prison;
	Arrest* arrest = new Arrest(prison);
	mapVector.push_back(arrest);
	mapVector.push_back(new Country("0"));
	mapVector.push_back(new Country("1"));
	mapVector.push_back(new Country("2"));
	mapVector.push_back(new Country("3"));
	mapVector.push_back(new PowerStation(0));
	mapVector.push_back(new Country("4"));
	mapVector.push_back(new Country("5"));
	mapVector.push_back(new Country("6"));
	mapVector.push_back(new ChanceGround);
	mapVector.push_back(new Country("7"));
	mapVector.push_back(new Country("8"));
	mapVector.push_back(new Country("9"));
	mapVector.push_back(prison);
	mapVector.push_back(new Country("10"));
	mapVector.push_back(new Country("11"));
	mapVector.push_back(new Country("12"));
	mapVector.push_back(new Country("13"));
	mapVector.push_back(new PowerStation(1));
	mapVector.push_back(new Country("14"));
	mapVector.push_back(new Country("15"));
	mapVector.push_back(new Country("16"));
	mapVector.push_back(new FateGround);
	mapVector.push_back(new Country("17"));
	mapVector.push_back(new Country("18"));
	mapVector.push_back(new Country("19"));
	mapVector.push_back(new Country("20"));

	Map map(mapVector);
	Dice dice;
	players = new Player[4];
	map.initPlayers();

	for (int j = 0; j <= 9; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			int n = 0;
			string mainText;
			vector<string> operations;
			string serverText;

			n = players[i].getPause();
			if (n > 0)
			{
				mainText = "You're suspended for this round.";
				serverText = "pause";
				Output::instance->print(mainText, serverText);

				players[i].bePaused();
				continue;
			}

			mainText = "It's No." + to_string(i+1) + "'s turn.\nPlease choose your operations.";
			operations = { "Shoot dice", "Search informations" };
			serverText = "choice";

			Menu menu(mainText, operations, serverText);

			while (n != 1)
			{
				n = menu.exec();

				switch (n)
				{
				case 1:
					int num;
					num = dice.getNum();
					mainText = "The result is " + to_string(num) + ".";
					serverText = "move" + to_string(num);
					Output::instance->print(mainText, serverText);

					map.movePlayer(i, num);
					break;

				case 2:
					players[i].show();
					break;
				}
			}
		}
	}
	return 0;
}