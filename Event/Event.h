#ifndef EVENT_EVENT_H
#define EVENT_EVENT_H

#include <iostream>
#include <string>
#include <list>
#include "EventHandler.h"

/**
* @brief 事件的基类
* 
* 要创建自定义事件，请勿手动继承该类，
* 而是使用REGISTER_INITIAL_EVENT与
* REGISTER_CHILD_EVENT注册事件类。
* 
* @see REGISTER_INITIAL_EVENT
* @see REGISTER_CHILD_EVENT
*/
class Event
{
private:
	friend class EventHandler;
	bool finished;
protected:
	std::list<std::string> classType;
public:
	virtual void* getObjAddr() = 0;                       ///< 不要手动使用该函数
	Event() : classType{}, finished{ false } {}           ///< 不要手动使用该函数
	~Event() { delete getObjAddr(); }                     ///< 不要手动使用该函数
};

/**
* @brief 将一个类注册为事件类
* 
* 此命令用于把一个父类未被注册为事件的类注册为事件类。
* 注册后，可用EMIT_EVENT发送该类事件
* 
* className为要注册的类名称
* 
* @attention 如果注册为事件的类的父类已被注册，请使用
* REGISTER_CHILD_EVENT
* 
*/
#define REGISTER_INITIAL_EVENT(className)                               \
class Event##className : public Event                                   \
{                                                                       \
private:                                                                \
	className *obj;                                                     \
	friend class EventHandler;                                          \
public:														            \
	Event##className() : obj(nullptr) { classType.insert(#className); } \
	className* getObj##className() { return obj; }                      \
	void setObj##className(className* obj) { this->obj = obj; }         \
	virtual void* getObjAddr(){ return static_cast<void*>(obj); }       \
}

/**
* @brief 把一个类注册为事件类
* 
* 此命令用于将一个父类已被注册的类注册为事件类。
* 注册后，可用EMIT_EVENT发送该类事件
* 
* className为要注册的类名称
* 
* parent为要注册的类的父类名称
* 
* @attention 如果注册为事件的类的父类未被注册，
* 请使用REGISTER_INITIAL_EVENT
*/
#define REGISTER_CHILD_EVENT(className, parent)                                          \
class Event##className : public Event##parent                                            \
{                                                                                        \
private:                                                                                 \
	className* obj;                                                                      \
	friend class EventHandler;                                                           \
public:                                                                                  \
	Event##className() : Event##parent(), obj(nullptr) { classType.insert(#className); } \
	className* getObj##className() { return obj; }                                       \
	void setObj##className(className* obj)                                               \
	{                                                                                    \
		this->obj = obj;                                                                 \
		setObj##parent(static_cast<parent*>(obj));                                       \
	}                                                                                    \
    virtual void* getObjAddr(){ return static_cast<void*>(obj); }                        \
}

/**
* @brief 发送一个事件
* 
* 事件发送后，会被所有监听器接收
* 
* className为要发送的事件类名
* 
* obj为要发送的事件对象
* 
* time为任意合法标识符或任意长度不为1
* 的合法标识符去掉其首个字符，用于指示
* 同一作用域内第几次使用该命令。同一作
* 用域下的所有EMIT_EVENT命令不能具有
* 相同的time
* 
* @attention 事件发送后，obj会被删除
*/
#define EMIT_EVENT(className, obj, time)                             \
{                                                                    \
    auto $__EVEptr_$##className##time = new Event##className();      \
    $__EVEptr_$##className##time->setObj##className(obj);            \
	EventHandler::instance->emitEvent($__EVEptr_$##className##time); \
}

#endif 