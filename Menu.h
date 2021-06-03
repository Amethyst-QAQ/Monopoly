#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include <regex>

extern bool isServer;

#define DEFAULT_WRONG_TEXT "Wrong input. Please input again."

/**
* @brief �˵��࣬���������������Ϣ
* 
* �˵���������ı�(mainText)�������б�(operations)���������ı���serverText��
* ������Ҫ��Ա�������˵���ʹ��exec()������ִ�в˵���
*/
class Menu
{
private:
	std::string _mainText;
	std::vector<std::string> _operations;
	std::string _serverText;
	std::vector<std::regex> regexes;
	std::string wrongText;

	void output();
	bool input(int *ret);

public:
	/**
	* @brief ���캯��
	* @param mainText ���ı�
	* @param operations �����б�
	* @param serverText �������ı�
	* 
	* @attention �˵����ʱ�����ı���ÿ���������������ı����涼���Զ����С�
	* ��ˣ������������Ϊ֮���벻Ҫ����Щ�ı���ĩβ��ӻ��з���
	* 
	* @attention �˵����ʱ��ÿ������֮ǰ���Զ������š���ˣ��������
	* ����Ϊ֮���벻Ҫ�ڲ����ı�ǰ�����š�
	* 
	* ������һ��ʾ����
	* 
	* @code
	* string mainText = "���ı�";
	* vector<string> operations = {"����1", "����2"};
	* string serverText = "server";
	* Menu menu(mainText, operations, serverText);
	* @endcode
	* 
	*/
	Menu(const std::string &mainText, const std::vector<std::string> &operations, const std::string &serverText);

	/**
	* @brief ִ�в˵�
	* 
	* ���д˺������������ڷ�����״̬�£��˵�����������ı��������б���ʽ
	* ��1. ����1    2. ����2    3. ����3��������������б���ÿ�����������
	* ����һ������֮�󣬸ú�����������Ĳ�����Ӧ����š�����������˴����
	* ���ݣ��˵�������ʾ����������Ҫ������������롣�����ڷ�����״̬�£�
	* �˵�������������ı������ȴ����������������
	* 
	* @return ������š�ע�⣺����Ŵ�1��ʼ
	* 
	* @attention ����һ����������ҵ��������붼���ж�Ϊ��Ч���룺
	* * �������
	* * �������.
	* * ������
	* * �������.������
	* * ������� ������
	* * �������. ������
	* 
	*/
	int exec();

	/**
	* @brief �����������ʱ����ҵĴ�����ʾ
	* 
	* Ĭ�ϵĴ�����ʾΪDEFAULT_WRONG_TEXT
	*/
	void setWrongText(const std::string &wrongText) { this->wrongText = wrongText; }
};

#endif