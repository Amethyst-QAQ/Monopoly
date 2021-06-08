#ifndef MAP_GROUND_H
#define MAP_GROUND_H

#include <string>

class Player;

/**
* @brief 地图的格子
* 
* 玩家从格子上经过但不停留时，会执行
* onPassed函数，停留时，会执行
* onStepped函数
*/
class Ground
{
private:
	std::string name;
	int position;
public:
	Ground(const std::string &_name = "") : name(_name), position(0) {}

	std::string getName() { return name; }
	int getPosition() { return position; }

	void setName(const std::string &name) { this->name = name; }
	void setPosition(int position) { this->position = position; }

	virtual void onStepped(Player *player);
	virtual void onPassed(Player *player);
};

#endif // !MAP_GROUND_H
