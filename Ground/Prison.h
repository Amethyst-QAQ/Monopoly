#ifndef GROUND_PRISON_H
#define GROUND_PRISON_H

#include "Ground.h"
#include "../Player/Player.h"

///��������

class Prison : public Ground
{
private:
	int pause;										/*��ͣ�غ���*/

public:
	Prison(int _pause) : pause(_pause) {}

	Prison() : pause(1) {}

	void beArrest(Player& a) { a.setPause(pause); }	/*ͨ���޸�Player������������ͣ�غ���*/
};

#endif // !PRISON_H



