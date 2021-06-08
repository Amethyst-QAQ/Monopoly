#ifndef PLAYER_PLAYER_H
#define PLAYER_PLAYER_H

#include <string>
#include <map>

class Player
{
private:
	std::string name;
	int money;
	int position;
	int num;
	std::map <std::string, int> properties;

public:
	Player() : name(), money(50000),num(0), position(0) {}

	void show();
	std::string getName() { return name; }
	int getMoney() { return money; }
	int getNum() { return num; }
	int getPosition() { return position; }
	int getProperty(const std::string &name);

	void setName(const std::string &name) { this->name = name; }
	void setNum(int num) { this->num = num; }
	void setMoney(int money)
	{
		this->money = money;
		if (money < 0)
			broke();
	}
	void setPosition(int position) { this->position = position; }
	void setProperty(const std::string &name, int value) { properties[name] = value; }
	void broke();
};

#endif // !PLAYER_PLAYER_H