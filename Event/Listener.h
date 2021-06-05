#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H

#include <string>

class BaseListener
{
private:
	std::string typeName;
	friend class EventHandler;
	virtual void onEventEmitted(void* event) = 0;
public:
	BaseListener(const std::string &_typeName) : typeName(_typeName)
	{
		EventHandler::instance->allListeners[typeName].insert(this);
	}

	~BaseListener()
	{
		EventHandler::instance->allListeners[typeName].erase(this);
	}
};

template<class T>
class Listener : public BaseListener
{
private:
	void (*onEvent)(T* event);
	friend class EventHandler;
	void onEventEmitted(void* event) { onEvent(dynamic_cast<T*>(event)); }
public:
	Listener(void (*_onEvent)(T *event), const std::string& _typeName) : 
		BaseListener(_typeName),
		onEvent(_onEvent){}
};

#define CREATE_LISTENER(type, func) new Listener<type>(func, #type)

#endif