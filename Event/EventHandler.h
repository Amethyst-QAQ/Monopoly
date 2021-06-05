#ifndef EVENT_EVENT_HANDLER_H
#define EVENT_EVENT_HANDLER_H

#include <string>
#include <map>
#include <set>

class Listener;
class Event;

/**
* @brief 事件处理系统
* 
* 用于把事件发送给监听器
* 
* 不要手动调用此类中除finishEvent外的函数
*/
class EventHandler
{
private:
	std::map<std::string, std::map<int, std::set<Listener*>>> allListeners;
	EventHandler() : allListeners(), finished(false) {}
	friend class Listener;
	bool finished;
public:
	static EventHandler* instance;  ///< 不要手动调用此变量
	void emitEvent(Event *event);   ///< 不要手动调用此函数
	/**
	* @brief 结束事件
	*
	* 在某个监听器中结束事件后，优先级更低的监听器将无法接收到事件
	*/
	void finishEvent()
	{
		finished = true;
	}
};

#endif