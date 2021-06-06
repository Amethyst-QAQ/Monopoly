#include "EventHandler.h"
#include "Event.h"
#include "Listener.h"

#include <vector>
#include <algorithm>

using namespace std;

EventHandler* EventHandler::instance{};

void EventHandler::emitEvent(Event* event)
{
	finished = false;

	for (auto i = event->classType.begin(); i != event->classType.end(); i++)
		if (allListeners[*i].size() > 0)
		{
			vector<int> priorities;
			for (auto j = allListeners[*i].begin(); j != allListeners[*i].end(); j++)
				if ((*j).second.size() > 0)
					priorities.push_back((*j).first);

			sort(priorities.begin(), priorities.end(), [](int a, int b) ->int {return a > b; });

			for(int j = 0; j < priorities.size(); j++)
					for (auto k = allListeners[*i][priorities[j]].begin(); k != allListeners[*i][priorities[j]].end(); k++)
						if(!finished)
							(*k)->onEventEmitted(event->getObjAddr());
		}
	delete event;
}
