#include "Map.h"
#include "../Player/Player.h"

MapNode* Map::findNodeFromPosition(Ground* position, int distance)
{
	MapNode* temp = beginning;
	while (temp->ground != position)
	{
		temp = temp->next;
	}

	for (int i = 0; i < distance; i++)
	{
		temp = temp->next;
	}
	return temp;
}

Map::Map(std::vector<Ground *> allGrounds)
{
	beginning = new MapNode(allGrounds[0], nullptr);
	MapNode *temp = beginning;
	for (int i = 1; i < allGrounds.size(); i++)
	{
		temp = new MapNode(allGrounds[i], temp);
	}
	beginning->prev = temp;
	beginning->prev->next = beginning;
}

Map::~Map()
{
	beginning->prev->next = nullptr;
	beginning->prev = nullptr;
	auto temp = beginning;
	while (temp->next != nullptr)
	{
		auto temp2 = temp->next;
		delete temp;
		temp = temp2;
	}
}

Ground *Map::findGroundFromPosition(Ground *position, int distance)
{
	return findNodeFromPosition(position, distance)->ground;
}

void Map::movePlayer(int player, int dice)
{
	auto node = findNodeFromPosition(players[player].getPosition(), 0);

	for (int i = 0; i < dice; i++)
	{
		node->ground->onPassed(player);
		node = node->next;
	}

	node->ground->onStepped(player);
	players[player].setPosition(node->ground);
}

void Map::initPlayers()
{
	for (int i = 0; i < 4; i++)
		players[i].setPosition(beginning->ground);
}
