#ifndef EVENT_EVENTS_GAME_START_EVENT_H
#define EVENT_EVENTS_GAME_START_EVENT_H

#include <string>
#include <vector>
#include "../Event.h"

class GameStartEvent
{
public:
	std::vector<std::string> players;
	GameStartEvent(const std::vector<std::string>& _players) : players{ _players } {}
};

REGISTER_INITIAL_EVENT(GameStartEvent);

#endif