#include "GameLogic.h"
#include <string>

bool isServer = false;

int main(int argc, char **argv)
{
	if (argc == 2 && argv[1] == std::string("server"))
		isServer = true;
	GameLogic logic;
	logic.startGame();
	while (logic.round());
	logic.cleanup();
	return 0;
}