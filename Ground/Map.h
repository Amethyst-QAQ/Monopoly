#ifndef GROUND_MAP_H
#define GROUND_MAP_H

#include "Ground.h"

#include <vector>

struct MapNode
{
	Ground *ground;
	MapNode *next;
	MapNode *prev;
	MapNode(Ground *_ground, MapNode *_prev) : ground(_ground), next(nullptr), prev(_prev) {}
	~MapNode() { delete ground; }
};

class Map
{
private:
	MapNode *beginning;
public:
	Map(std::vector<Ground*> allGrounds);
	~Map();
	Ground *findGroundFromPosition(Ground *position, int distance);
};

#endif