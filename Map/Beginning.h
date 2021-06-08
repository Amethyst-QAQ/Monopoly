#ifndef MAP_BEGINNING_H
#define MAP_BEGINNING_H

#include "Ground.h"
#include "../IO/Output.h"

class Beginning : public Ground
{
public:
	Beginning() : Ground("Beginning"){}
	void show()
	{
		Ground::show();
		Output::instance->print("Name: Beginning Ground", "show_name_Beginning");
	}
	virtual void onPassed(Player *player);
};

#endif // !MAP_BEGINNING_H
