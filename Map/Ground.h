#ifndef MAP_GROUND_H
#define MAP_GROUND_H

#include <string>

class Player;

/**
* @brief ��ͼ�ĸ���
* 
* ��ҴӸ����Ͼ�������ͣ��ʱ����ִ��
* onPassed������ͣ��ʱ����ִ��
* onStepped����
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
