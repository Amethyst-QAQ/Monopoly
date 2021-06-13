#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H

#include "EventHandler.h"

#include <string>

/**
* @brief 事件监听器的共同基类
* 
* 不要手动创建此类对象
*/
class Listener
{
private:
	std::string typeName;
	friend class EventHandler;
	virtual void onEventEmitted(void* event) = 0;
	int priority;
public:
	/// 不要手动调用此函数
	Listener(const std::string &_typeName, int _priority) : typeName(_typeName), priority(_priority)
	{
		EventHandler::instance->allListeners[typeName][priority].insert(this);
	}

	/// 不要手动调用此函数
	~Listener()
	{
		EventHandler::instance->allListeners[typeName][priority].erase(this);
	}
};

/**
* @brief 事件监听器类模板
* 
* 不要手动创建此类对象，使用
* CREATE_LISTENER自动创建
* 
* @see CREATE_LISTENER
*/
template<class T>
class TypeListener : public Listener
{
private:
	void (*onEvent)(T* event);
	friend class EventHandler;
	void onEventEmitted(void* event) { onEvent((T*)(event)); }
public:
	/// 不要手动调用此函数
	TypeListener(void (*_onEvent)(T *event), const std::string& _typeName, int priority) : 
		Listener(_typeName, priority),
		onEvent(_onEvent){}
};

/**
* @brief 创建一个事件监听器
* 
* 该命令内部使用了new，创建出的对象需要手动delete
* 
* type为监听器监听的事件类名称
* 
* func为监听器接收到事件后执行的函数指针
*/
#define CREATE_LISTENER(type, func, priority) dynamic_cast<Listener*>(new TypeListener<type>(func, #type, priority))

#endif