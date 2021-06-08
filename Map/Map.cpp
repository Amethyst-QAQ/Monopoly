#include "Map.h"

#include "Ground.h"
#include "../Player/Player.h"
#include "Country.h"

Map *Map::instance = new Map();

void Map::initGrounds(std::vector<Ground *> allGrounds)
{
	beginning = new MapNode(allGrounds[0], nullptr);
	MapNode *temp = beginning;
	allNodes.push_back(temp);
	for (int i = 1; i < allGrounds.size(); i++)
	{
		temp = new MapNode(allGrounds[i], temp);
		temp->index = allNodes.size();
		allGrounds[i]->setPosition(temp->index);

		allNodes.push_back(temp);

		if (dynamic_cast<Country *>(allGrounds[i]))
		{
			auto tempCountry = dynamic_cast<Country *>(allGrounds[i]);
			if (getCountryAmount(tempCountry->getColor()) == 0)
				countryAmounts[tempCountry->getColor()] = 0;
			countryAmounts[tempCountry->getColor()]++;
		}
	}
	beginning->prev = temp;
	beginning->prev->next = beginning;
}

Map::~Map()
{
	for (int i = 0; i < allNodes.size(); i++)
		delete allNodes[i];
}

void Map::movePlayer(Player *player, int distance)
{
	auto currentNode = allNodes[player->getPosition()];
	for (int i = 0; i < distance; i++)
	{
		currentNode->ground->onPassed(player);
		currentNode = currentNode->next;
	}
	currentNode->ground->onStepped(player);
	player->setPosition(currentNode->index);
}

void Map::movePlayerTo(Player *player, int position)
{
	if (position >= getSize())
		return;
	auto currentNode = allNodes[player->getPosition()];
	while(currentNode->index != position)
	{
		currentNode->ground->onPassed(player);
		currentNode = currentNode->next;
	}
	currentNode->ground->onStepped(player);
	player->setPosition(currentNode->index);
}

Ground *Map::getGround(int position)
{
	return allNodes[position]->ground;
}

Ground *Map::findGround(int position, int distance)
{
	auto currentNode = allNodes[position];
	for (int i = 0; i < distance; i++)
		currentNode = currentNode->next;
	return currentNode->ground;
}

int Map::getCountryAmount(int color)
{
	auto i = countryAmounts.find(color);
	if (i != countryAmounts.end())
		return (*i).second;
	return 0;
}

void Map::show()
{
	MapNode* a = beginning;
	while(true)
	{
		a->ground->show();
		a = a->next;
		if (a == beginning)
			return;
	}
}
