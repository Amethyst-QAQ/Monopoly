#include "StockListeners.h"
#include "Stock.h"

StockListeners StockListeners::instance{};

void StockListeners::addMenuOperation(InitMenuEvent* event)
{
	buyStock = event->operations.size();
	event->operations.push_back("Buy stock");
	sellStock = event->operations.size();
	event->operations.push_back("Sell stock");
}

void StockListeners::execMenu(RoundEvent* event)
{
	Player* player = &GameLogic::instance->getPlayer(event->player);

	if (event->operation == buyStock)
	{
		
	}
}
