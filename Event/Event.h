#ifndef EVENT_EVENT_H
#define EVENT_EVENT_H

#include <iostream>
#include <string>
#include <list>
#include "EventHandler.h"

/**
* @brief �¼��Ļ���
* 
* Ҫ�����Զ����¼��������ֶ��̳и��࣬
* ����ʹ��REGISTER_INITIAL_EVENT��
* REGISTER_CHILD_EVENTע���¼��ࡣ
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
	virtual void* getObjAddr() = 0;                       ///< ��Ҫ�ֶ�ʹ�øú���
	Event() : classType{}, finished{ false } {}           ///< ��Ҫ�ֶ�ʹ�øú���
	~Event() { delete getObjAddr(); }                     ///< ��Ҫ�ֶ�ʹ�øú���
};

/**
* @brief ��һ����ע��Ϊ�¼���
* 
* ���������ڰ�һ������δ��ע��Ϊ�¼�����ע��Ϊ�¼��ࡣ
* ע��󣬿���EMIT_EVENT���͸����¼�
* 
* classNameΪҪע���������
* 
* @attention ���ע��Ϊ�¼�����ĸ����ѱ�ע�ᣬ��ʹ��
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
* @brief ��һ����ע��Ϊ�¼���
* 
* ���������ڽ�һ�������ѱ�ע�����ע��Ϊ�¼��ࡣ
* ע��󣬿���EMIT_EVENT���͸����¼�
* 
* classNameΪҪע���������
* 
* parentΪҪע�����ĸ�������
* 
* @attention ���ע��Ϊ�¼�����ĸ���δ��ע�ᣬ
* ��ʹ��REGISTER_INITIAL_EVENT
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
* @brief ����һ���¼�
* 
* �¼����ͺ󣬻ᱻ���м���������
* 
* classNameΪҪ���͵��¼�����
* 
* objΪҪ���͵��¼�����
* 
* timeΪ����Ϸ���ʶ�������ⳤ�Ȳ�Ϊ1
* �ĺϷ���ʶ��ȥ�����׸��ַ�������ָʾ
* ͬһ�������ڵڼ���ʹ�ø����ͬһ��
* �����µ�����EMIT_EVENT����ܾ���
* ��ͬ��time
* 
* @attention �¼����ͺ�obj�ᱻɾ��
*/
#define EMIT_EVENT(className, obj, time)                             \
{                                                                    \
    auto $__EVEptr_$##className##time = new Event##className();      \
    $__EVEptr_$##className##time->setObj##className(obj);            \
	EventHandler::instance->emitEvent($__EVEptr_$##className##time); \
}

#endif 