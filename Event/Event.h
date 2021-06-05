#ifndef EVENT_EVENT_H
#define EVENT_EVENT_H

#include <iostream>
#include <string>
#include <set>
#include "EventHandler.h"

class Event
{
private:
	friend class EventHandler;
protected:
	std::set<std::string> classType;
public:
	virtual void* getObjAddr() = 0;
	Event() : classType{} {}
	~Event() { delete getObjAddr(); }
};

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

#define EMIT_EVENT(className, obj, time)                         \
auto $__EVEptr_$##className##time = new Event##className();      \
$__EVEptr_$##className##time->setObj##className(obj);            \
EventHandler::instance->emitEvent($__EVEptr_$##className##time); \

#endif 