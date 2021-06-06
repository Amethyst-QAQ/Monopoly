#ifndef GROUND_PRISON_H
#define GROUND_PRISON_H

#include "Ground.h"
#include "../Player/Player.h"

extern Player* players;

///��������

class Prison : public Ground
{
private:
	int pause;										/*��ͣ�غ���*/

public:
	Prison() : pause(1) {}
	Prison(int _pause) : pause(_pause) {}

	void beArrested(int player) { players[player].changePause(pause); }	/*ͨ���޸�Player������������ͣ�غ���*/
};

#endif // !PRISON_H



