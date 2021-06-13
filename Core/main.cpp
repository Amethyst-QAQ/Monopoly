#include "GameLogic.h"
#include <string>
#include <cstdlib>
#include <time.h>

bool isServer = false;

int main(int argc, char **argv)
{
	srand(time(NULL));
	std::srand(time(NULL));
	if (argc == 2 && argv[1] == std::string("server"))
		isServer = true;
	GameLogic logic;
	GameLogic::instance = &logic;
	logic.startGame();
	while (logic.round());
	logic.cleanup();
	return 0;
}