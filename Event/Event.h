#ifndef EVENT_H
#define EVEMT_H

#include <iostream>
#include <string>
#include <set>

class Event
{
protected:
	std::set<std::string> classType;
};

#define REGISTER_INITIAL_EVENT(name)                          \
class Event##name : public Event                              \
{                                                             \
private:                                                      \
	name *obj;                                                \
public:                                                       \
	Event##name() : obj(nullptr) { classType.insert(#name); } \
	name* getObj##name() { return obj; }                      \
	void setObj##name(name* obj) { this->obj = obj; }         \
}

#define REGISTER_CHILD_EVENT(name, parent)                                     \
class Event##name : public Event##parent                                       \
{                                                                              \
private:                                                                       \
	name* obj;                                                                 \
public:                                                                        \
	Event##name() : Event##parent(), obj(nullptr) { classType.insert(#name); } \
	name* getObj##name() { return obj; }                                       \
	void setObj##name(name* obj)                                               \
	{                                                                          \
		this->obj = obj;                                                       \
		setObj##parent(static_cast<parent*>(obj));                             \
	}                                                                          \
}

#endif 

