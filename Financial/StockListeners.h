#ifndef FINANCIAL_STOCK_LISTENERS_H
#define FINANCIAL_STOCK_LISTENERS_H

#include "../Event/Events/AllEvents.h"

typedef void(*pAddMenuOperation)(InitMenuEvent* event);
typedef void(*pExecMenu)(RoundEvent* event);

class StockListeners
{
private:
	Listener* initMenuListener;
	Listener* roundListener;

public:
	StockListeners() :
		initMenuListener(CREATE_LISTENER(InitMenuEvent, (pAddMenuOperation)addMenuOperation, 10)),
		roundListener(CREATE_LISTENER(RoundEvent, (pExecMenu)execMenu, 10)){}
	static int buyStock;
	static int sellStock;
	static void addMenuOperation(InitMenuEvent* event);
	static void execMenu(RoundEvent* event);

	static StockListeners instance;
};

#endif // !FINANCIAL_STOCK_LISTENERS_H
