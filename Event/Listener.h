#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H

#include "EventHandler.h"

#include <string>

/**
* @brief �¼��������Ĺ�ͬ����
* 
* ��Ҫ�ֶ������������
*/
class Listener
{
private:
	std::string typeName;
	friend class EventHandler;
	virtual void onEventEmitted(void* event) = 0;
	int priority;
public:
	/// ��Ҫ�ֶ����ô˺���
	Listener(const std::string &_typeName, int _priority) : typeName(_typeName), priority(_priority)
	{
		EventHandler::instance->allListeners[typeName][priority].insert(this);
	}

	/// ��Ҫ�ֶ����ô˺���
	~Listener()
	{
		EventHandler::instance->allListeners[typeName][priority].erase(this);
	}
};

/**
* @brief �¼���������ģ��
* 
* ��Ҫ�ֶ������������ʹ��
* CREATE_LISTENER�Զ�����
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
	/// ��Ҫ�ֶ����ô˺���
	TypeListener(void (*_onEvent)(T *event), const std::string& _typeName, int priority) : 
		Listener(_typeName, priority),
		onEvent(_onEvent){}
};

/**
* @brief ����һ���¼�������
* 
* �������ڲ�ʹ����new���������Ķ�����Ҫ�ֶ�delete
* 
* typeΪ�������������¼�������
* 
* funcΪ���������յ��¼���ִ�еĺ���ָ��
*/
#define CREATE_LISTENER(type, func, priority) dynamic_cast<Listener*>(new TypeListener<type>(func, #type, priority))

#endif