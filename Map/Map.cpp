#include "Map.h"

#include "Ground.h"
#include "../Player/Player.h"

Map::Map(std::vector<Ground *> allGrounds) : allNodes()
{
	beginning = new MapNode(allGrounds[0], nullptr);
	MapNode *temp = beginning;
	for (int i = 1; i < allGrounds.size(); i++)
	{
		temp = new MapNode(allGrounds[i], temp);
		temp->index = allNodes.size();
		allNodes.push_back(temp);
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

