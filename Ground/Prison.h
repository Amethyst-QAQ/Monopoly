#ifndef PRISON_H
#define PRISON_H

#include "Ground.h"
#include "Person.h"

/*监狱格子*/

class Prison : public Ground
{
private:
	int pause;										/*暂停回合数*/

public:
	Prison(int _pause) : pause(_pause) {}

	Prison() : pause(1) {}

	void beArrest(Person& a) { a.setPause(pause); }	/*通过修改person的属性设置暂停回合数*/
};

#endif // !PRISON_H



