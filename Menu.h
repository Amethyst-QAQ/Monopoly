#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include <regex>

extern bool isServer;

class Menu
{
private:
	std::string _mainText;
	std::vector<std::string> _operations;
	std::string _serverText;
	std::vector<std::regex> regexes;

	void output();
	bool input(int *ret);

public:
	Menu(const std::string &mainText, const std::vector<std::string> &operations, const std::string &serverText);

	int exec();
};

#endif