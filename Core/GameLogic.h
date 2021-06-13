#ifndef CORE_GAME_LOGIC_H
#define CORE_GAME_LOGIC_H

#include "../Player/Player.h"
#include <vector>
#include <string>

class GameLogic
{
private:
	Player *players;
	int playerAmount;
	std::vector<std::string> mainOperations;
	void initPlayers();
	void initMap();
	void initFateSuit();
	void initChanceSuit();
	void initMainOperations();
	void searchInfomation(Player *player);

public:
	GameLogic() : players(nullptr), playerAmount(0), mainOperations() {}
	void startGame();
	bool round();
	void cleanup();
	Player& getPlayer(int index) { return players[index]; }
	static GameLogic* instance;
};

#endif // !CORE_GAME_LOGIC_H
