#include "Output.h"
#include <iostream>
#include <fstream>

using namespace std;

Output *Output::instance = new Output();

Output::~Output()
{
	ofstream fout("textMap.txt");
	for (auto i = textMap.begin(); i != textMap.end(); i++)
		fout << (*i).first << "\t" << (*i).second << "\n";
	fout << endl;
}

void Output::print(std::string text, std::string serverText)
{
	textMap[text] = serverText;

	if (isServer)
		cout << text << endl;
	else
		cout << serverText << endl;
}
