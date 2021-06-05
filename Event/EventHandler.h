#ifndef EVENT_EVENT_HANDLER_H
#define EVENT_EVENT_HANDLER_H

#include <string>
#include <map>
#include <set>

class BaseListener;
class Event;

class EventHandler
{
private:
	std::map<std::string, std::set<BaseListener*>> allListeners;
	EventHandler() : allListeners() {}
	friend class BaseListener;
public:
	static EventHandler* instance;
	void emitEvent(Event *event);
};

#endif