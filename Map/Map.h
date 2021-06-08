#ifndef GROUND_MAP_H
#define GROUND_MAP_H

#include "Ground.h"

#include <vector>

class Player;
extern Player* players;

struct MapNode
{
	Ground *ground;
	MapNode *next;
	MapNode *prev;
	MapNode(Ground *_ground, MapNode *_prev) : ground(_ground), next(nullptr), prev(_prev)
	{
		if(_prev != nullptr)
			_prev->next = this;
	}
	~MapNode() { delete ground; }
};

class Map
{
private:
	MapNode *beginning;
	MapNode* findNodeFromPosition(Ground* position, int distance);
public:
	Map(std::vector<Ground*> allGrounds);
	~Map();
	Ground *findGroundFromPosition(Ground *position, int distance);
	void movePlayer(int player, int dice);
	void initPlayers();
};

#endif