#include "Map.h"

Map::Map(std::vector<Ground *> allGrounds)
{
	beginning = new MapNode(allGrounds[0], nullptr);
	MapNode *temp = beginning;
	for (int i = 1; i < allGrounds.size(); i++)
	{
		temp = new MapNode(allGrounds[i], temp);
	}
	beginning->prev = temp;
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
	MapNode *temp = beginning;
	while (temp->ground != position)
	{
		temp = temp->next;
	}

	for (int i = 0; i < distance; i++)
	{
		temp = temp->next;
	}
	return temp->ground;
}
