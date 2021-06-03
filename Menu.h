#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include <regex>

extern bool isServer;

#define DEFAULT_WRONG_TEXT "Wrong input. Please input again."

/**
* @brief 菜单类，用于输出并输入信息
* 
* 菜单类具有主文本(mainText)，操作列表(operations)，服务器文本（serverText）
* 三个主要成员。创建菜单后，使用exec()函数来执行菜单。
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
	* @brief 构造函数
	* @param mainText 主文本
	* @param operations 操作列表
	* @param serverText 服务器文本
	* 
	* @attention 菜单输出时，主文本、每条操作、服务器文本后面都会自动换行。
	* 因此，如果不是有意为之，请不要在这些文本的末尾添加换行符。
	* 
	* @attention 菜单输出时，每条操作之前会自动添加序号。因此，如果不是
	* 有意为之，请不要在操作文本前添加序号。
	* 
	* 以下是一个示例：
	* 
	* @code
	* string mainText = "主文本";
	* vector<string> operations = {"操作1", "操作2"};
	* string serverText = "server";
	* Menu menu(mainText, operations, serverText);
	* @endcode
	* 
	*/
	Menu(const std::string &mainText, const std::vector<std::string> &operations, const std::string &serverText);

	/**
	* @brief 执行菜单
	* 
	* 运行此函数后，若不处于服务器状态下，菜单会先输出主文本，再以列表形式
	* （1. 操作1    2. 操作2    3. 操作3……）输出操作列表中每条操作。玩家
	* 输入一个操作之后，该函数返回输入的操作对应的序号。若玩家输入了错误的
	* 内容，菜单将会提示玩家输入错误并要求玩家重新输入。若处于服务器状态下，
	* 菜单会输出服务器文本，并等待服务器输入操作。
	* 
	* @return 操作序号。注意：该序号从1开始
	* 
	* @attention 对于一个操作，玩家的以下输入都被判断为有效输入：
	* * 操作序号
	* * 操作序号.
	* * 操作名
	* * 操作序号.操作名
	* * 操作序号 操作名
	* * 操作序号. 操作名
	* 
	*/
	int exec();

	/**
	* @brief 更改输入错误时对玩家的错误提示
	* 
	* 默认的错误提示为DEFAULT_WRONG_TEXT
	*/
	void setWrongText(const std::string &wrongText) { this->wrongText = wrongText; }
};

#endif