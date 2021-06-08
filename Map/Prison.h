#ifndef GROUND_PRISON_H
#define GROUND_PRISON_H

#include "Ground.h"
#include "../Player/Player.h"

extern Player* players;

///监狱格子

class Prison : public Ground
{
private:
	int pause;										/*暂停回合数*/

public:
	Prison() : pause(1) {}
	Prison(int _pause) : pause(_pause) {}

	void beArrested(int player) { players[player].changePause(pause); }	/*通过修改Player的属性设置暂停回合数*/
};

#endif // !PRISON_H



