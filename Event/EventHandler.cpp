#include "EventHandler.h"
#include "Event.h"
#include "Listener.h"

EventHandler* EventHandler::instance{};

void EventHandler::emitEvent(Event* event)
{
	for (auto i = event->classType.begin(); i != event->classType.end(); i++)
		if (allListeners[*i].size() > 0)
			for (auto j = allListeners[*i].begin(); j != allListeners[*i].end(); j++)
				(*j)->onEventEmitted(event->getObjAddr());
	delete event;
}
