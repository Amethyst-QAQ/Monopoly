#ifndef MAP_MAP_H
#define MAP_MAP_H

#include <vector>
#include <map>

class Ground;
class Player;

struct MapNode
{
	Ground *ground;
	MapNode *next;
	MapNode *prev;
	int index;
	MapNode(Ground *_ground, MapNode *_prev) : ground(_ground), next(nullptr), prev(_prev), index(0)
	{
		if (_prev != nullptr)
			_prev->next = this;
	}
	~MapNode() { delete ground; }
};

class Map
{
private:
	MapNode *beginning;
	std::vector<MapNode *> allNodes;
	std::map<int, int> countryAmounts;
	Map() : beginning(nullptr), allNodes(), countryAmounts(){}
public:
	void initGrounds(std::vector<Ground *> allGrounds);
	~Map();
	void movePlayer(Player *player, int distance);
	void movePlayerTo(Player *player, int position);
	Ground *getGround(int position);
	Ground *findGround(int position, int distance);
	int getSize() { return allNodes.size(); }
	int getCountryAmount(int color);
	void show();
	static Map *instance;
};

#endif // !MAP_MAP_H
