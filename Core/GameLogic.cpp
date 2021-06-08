#include "GameLogic.h"
#include "../Player/Player.h"
#include "../Map/Map.h"
#include "../Map/AllGrounds.h"
#include "../CardsDrawing/FateSuit.h"
#include "../CardsDrawing/ChanceSuit.h"
#include "../IO/Menu.h"
#include "../IO/Output.h"
#include "../CardsDrawing/FateSuit/Fate_1.h"

#include"../CardsDrawing/ChanceSuit/Chance_1.h"
#include"../CardsDrawing/ChanceSuit/Chance_2.h"
#include"../CardsDrawing/ChanceSuit/Chance_3.h"
#include"../CardsDrawing/ChanceSuit/Chance_4.h"
#include"../CardsDrawing/ChanceSuit/Chance_5.h"
#include"../CardsDrawing/ChanceSuit/Chance_6.h"
#include"../CardsDrawing/ChanceSuit/Chance_7.h"
#include"../CardsDrawing/ChanceSuit/Chance_8.h"
#include"../CardsDrawing/ChanceSuit/Chance_9.h"
#include"../CardsDrawing/ChanceSuit/Chance_10.h"


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
	vector<Ground*> mapVector;
	mapVector.push_back(new Beginning);
	Prison* prison = new Prison;
	Arrest* arrest = new Arrest(22);
	Country* country;

	country = new Country("China", 2000, 1);                      //中国
	mapVector.push_back(country);
	country = new Country("Japan", 1400, 2);                        //日本
	mapVector.push_back(country);
	country = new Country("South Korea", 1600, 3);            //韩国
	mapVector.push_back(country);
	country = new Country("Syria", 600, 4);                         //叙利亚
	mapVector.push_back(country);
	//mapVector.push_back(new PowerStation(0));
	country = new Country("Pakistan", 800, 5);                   //巴基斯坦
	mapVector.push_back(country);
	country = new Country("Maldives", 1600, 6);                 //马尔代夫
	mapVector.push_back(country);
	country = new Country("Philippines", 1400, 7);            //菲律宾
	mapVector.push_back(country);
	mapVector.push_back(new ChanceGround);
	country = new Country("Bangladesh", 1000, 1);              //孟加拉国
	mapVector.push_back(country);
	country = new Country("India", 800, 2);                         //印度
	mapVector.push_back(country);
	country = new Country("Sri Lanka", 800, 3);                 //斯里兰卡
	mapVector.push_back(country);
	mapVector.push_back(arrest);
	country = new Country("Saudi Arabia", 2000, 4);         //沙特阿拉伯
	mapVector.push_back(country);
	country = new Country("Afghanistan", 800, 5);             //阿富汗
	mapVector.push_back(country);
	country = new Country("Israel", 600, 6);                      //以色列
	mapVector.push_back(country);
	country = new Country("Turkey", 1600, 7);                     //土耳其
	mapVector.push_back(country);
	//mapVector.push_back(new PowerStation(1));
	country = new Country("Russia", 1000, 1);                      //俄罗斯
	mapVector.push_back(country);
	country = new Country("Kazakhstan", 800, 2);              //哈萨克斯坦
	mapVector.push_back(country);
	country = new Country("Vietnam", 800, 3);                    //越南
	mapVector.push_back(country);
	mapVector.push_back(new FateGround);
	country = new Country("Cambodia", 400, 4);                   //柬埔寨
	mapVector.push_back(country);
	country = new Country("Thailand", 1400, 5);                 //泰国
	mapVector.push_back(country);
	mapVector.push_back(prison);
	country = new Country("Malaysia", 1600, 6);                 //马来西亚
	mapVector.push_back(country);
	country = new Country("Singapore", 1600, 7);               //新加坡
	mapVector.push_back(country);
	country = new Country("Indonesia", 800, 1);                 //印度尼西亚

	Map::instance->initGrounds(mapVector);
}

void GameLogic::initFateSuit()
{
	for (int i = 1;i <= 10;i++)
	{
	Fate_1* fate = new Fate_1;
	FateSuit::instance->add(fate);
	}
}

void GameLogic::initChanceSuit()
{
	//在此处初始化ChanceSuit::instance
	Chance_1* chance_1=new Chance_1;
	Chance_2* chance_2 = new Chance_2;
	Chance_3* chance_3 = new Chance_3;
	Chance_4* chance_4 = new Chance_4;
	Chance_5* chance_5 = new Chance_5;
	Chance_6* chance_6 = new Chance_6;
	Chance_7* chance_7 = new Chance_7;
	Chance_8* chance_8 = new Chance_8;
	Chance_9* chance_9 = new Chance_9;
	Chance_10* chance_10 = new Chance_10;

	ChanceSuit::instance->add(chance_1);
	ChanceSuit::instance->add(chance_2);
	ChanceSuit::instance->add(chance_3);
	ChanceSuit::instance->add(chance_4);
	ChanceSuit::instance->add(chance_5);
	ChanceSuit::instance->add(chance_6);
	ChanceSuit::instance->add(chance_7);
	ChanceSuit::instance->add(chance_8);
	ChanceSuit::instance->add(chance_9);
	ChanceSuit::instance->add(chance_10);


}

void GameLogic::initMainOperations()
{
	mainOperations.push_back("Throw dice");
	mainOperations.push_back("Search information");
}

void GameLogic::startGame()
{
	initMainOperations();
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
			if (players[i].getProperty("Pause") > 0)
				players[i].setProperty("Pause", players[i].getProperty("Pause") - 1);
			else
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
