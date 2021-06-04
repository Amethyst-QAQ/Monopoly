#include "Menu.h"
#include "Output.h"
#include <iostream>

using namespace std;

void Menu::output()
{
	if (!isServer)
	{
		cout << _mainText << "\n";
		for (int i = 0; i < _operations.size() - 1; i++)
			cout << to_string(i + 1) + ". " + _operations[i] << "\n";

		cout << to_string(_operations.size()) + ". " + _operations[_operations.size() - 1] << endl;
	}
	else
		cout << _serverText << endl;

	string all = _mainText + "    ";
	for (int i = 0; i < _operations.size(); i++)
		all += to_string(i + 1) + ". " + _operations[i] + "    ";
	Output::instance->textMap[all] = _serverText;
}

bool Menu::input(int *ret)
{
	string buffer;
	getline(cin, buffer);

	for (int i = 0; i < _operations.size(); i++)
	{
		if (regex_match(buffer, regexes[i]))
		{
			*ret = i + 1;
			return true;
		}
	}
	
	cout << wrongText << endl;
	return false;
}

Menu::Menu(const std::string &mainText, const std::vector<std::string> &operations, const std::string &serverText):
	_mainText{mainText}, _operations{operations}, _serverText{serverText}, regexes{}, wrongText{DEFAULT_WRONG_TEXT}
{
	for (int i = 0; i < operations.size(); i++)
	{
		regexes.push_back(regex(
			"\\s*(" + to_string(i + 1) + "[\\.\\s]?\\s*)?(" + operations[i] + ")?\\s*"
		));
	}
}

int Menu::exec()
{
	int ret;
	do
	{
		output();
	} while (!input(&ret));

	return ret;
}
