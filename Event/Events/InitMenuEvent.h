#ifndef EVENT_EVENTS_INIT_MENU_EVENT_H
#define EVENT_EVENTS_INIT_MENU_EVENT_H

#include <vector>
#include <string>
#include "../Event.h"

class InitMenuEvent
{
public:
	std::vector<std::string>& operations;
	InitMenuEvent(std::vector<std::string>& _operations) : operations(_operations) {}
};

REGISTER_INITIAL_EVENT(InitMenuEvent);

#endif // !EVENT_EVENTS_INIT_MENU_EVENT_H
