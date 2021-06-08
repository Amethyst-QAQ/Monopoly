#ifndef PLAYER_OUTPUT_H
#define PLAYER_OUTPUT_H

#include <string>
#include <map>

extern bool isServer;

/**
* @brief �����������
* 
* ʹ��Output::instance->print�������
*/
class Output
{
private:
	std::map<std::string, std::string> textMap;
	friend class Menu;
	Output() : textMap(){}
public:
	~Output();

	/**
	* �����Ψһʵ������
	*/
	static Output *instance;

	/**
	* @brief �������
	* 
	* @param text ���ı�
	* @param serverText �������ı�
	* 
	* ִ�иú���ʱ���������ڷ�����״̬�£���������ı�����������������ı�
	*/
	void print(std::string text, std::string serverText);
};

#endif