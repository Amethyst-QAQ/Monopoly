#ifndef EVENT_EVENT_HANDLER_H
#define EVENT_EVENT_HANDLER_H

#include <string>
#include <map>
#include <set>

class Listener;
class Event;

/**
* @brief �¼�����ϵͳ
* 
* ���ڰ��¼����͸�������
* 
* ��Ҫ�ֶ����ô����г�finishEvent��ĺ���
*/
class EventHandler
{
private:
	std::map<std::string, std::map<int, std::set<Listener*>>> allListeners;
	EventHandler() : allListeners(), finished(false) {}
	friend class Listener;
	bool finished;
public:
	static EventHandler* instance;  ///< ��Ҫ�ֶ����ô˱���
	void emitEvent(Event *event);   ///< ��Ҫ�ֶ����ô˺���
	/**
	* @brief �����¼�
	*
	* ��ĳ���������н����¼������ȼ����͵ļ��������޷����յ��¼�
	*/
	void finishEvent()
	{
		finished = true;
	}
};

#endif