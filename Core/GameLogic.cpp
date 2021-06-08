#include "GameLogic.h"
#include "../Player/Player.h"
#include "../Map/Map.h"
#include "../Map/AllGrounds.h"
#include "../CardsDrawing/FateSuit.h"
#include "../CardsDrawing/ChanceSuit.h"
#include "../IO/Menu.h"
#include "../IO/Output.h"

#include <iostream>

using namespace std;

void GameLogic::initPlayers()
{
	Menu playerAmountMenu(
		"Please input the amount of players",
		{},
		"player_amount"
	);

	playerAmount = playerAmountMenu.exec();

	players = new Player[playerAmount];

	for (int i = 0; i < playerAmount; i++)
	{
		Output::instance->print(
			"Please input Player No." + to_string(i + 1) + "'s name",
			"name(" + to_string(i + 1) + ")"
		);
		string buffer;
		getline(cin, buffer);
		players[i].setName(buffer);
	}
}

void GameLogic::initMap()
{
	//在此处初始化Map::instance
}

void GameLogic::initFateSuit()
{
	//在此处初始化FateSuit::instance
}

void GameLogic::initChanceSuit()
{
	//在此处初始化ChanceSuit::instance
}

void GameLogic::initMainOperations()
{
	mainOperations.push_back("Throw dice");
	mainOperations.push_back("Search information");
}

void GameLogic::startGame()
{
	initPlayers();
	initMap();
	initFateSuit();
	initChanceSuit();
}

bool GameLogic::round()
{
	int failedPlayers = 0;
	for (int i = 0; i < playerAmount; i++)
	{
		if (players[i].getProperty("failed"))
		{
			failedPlayers++;
			continue;
		}

		Menu menu(
			"This is Player " + players[i].getName() + "'s turn.",
			mainOperations,
			"choice " + to_string(i + 1)
		);

		int operation = menu.exec();

		switch (operation)
		{
		case 1:
		{
			int distance = rand() % 6 + rand() % 6 + 2;
			Output::instance->print(
				"The result is " + to_string(distance),
				"dice(" + to_string(distance) + ")"
			);
			Map::instance->movePlayer(players + i, distance);
			break;
		}
		case 2:
			searchInfomation(players + i);
			break;
		}
	}
	if (failedPlayers == playerAmount)
		return false;
	return true;
}

void GameLogic::searchInfomation(Player *player)
{
}

void GameLogic::cleanup()
{
	delete[] players;
	delete Map::instance;
	delete FateSuit::instance;
	delete ChanceSuit::instance;
	delete Output::instance;
}
