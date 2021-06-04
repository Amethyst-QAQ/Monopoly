#ifndef PLAYER_OUTPUT_H
#define PLAYER_OUTPUT_H

#include <string>
#include <map>

extern bool isServer;

/**
* @brief 用于输出的类
* 
* 使用Output::instance->print来输出。
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
	* 该类的唯一实例对象
	*/
	static Output *instance;

	/**
	* @brief 输出函数
	* 
	* @param text 主文本
	* @param serverText 服务器文本
	* 
	* 执行该函数时，若不处于服务器状态下，则输出主文本，否则输出服务器文本
	*/
	void print(std::string text, std::string serverText);
};

#endif