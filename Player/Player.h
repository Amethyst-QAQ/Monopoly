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
	std::map <std::string, int> properties;
public:

	Player() : name(), money(50000), position(0) {}

	std::string getName() { return name; }
	int getMoney() { return money; }
	int getPosition() { return position; }
	int getProperty(const std::string &name);

	void setName(const std::string &name) { this->name = name; }
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
