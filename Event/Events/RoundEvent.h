#ifndef EVENT_EVENTS_ROUND_EVENT_H
#define EVENT_EVENTS_ROUND_EVENT_H

#include "../Event.h"

class RoundEvent
{
public:
	const int player;
	const int operation;
	RoundEvent(int _player, int _operation) : player(_player), operation(_operation) {}
};

REGISTER_INITIAL_EVENT(RoundEvent);

#endif // !EVENT_EVENTS_ROUND_EVENT_H
