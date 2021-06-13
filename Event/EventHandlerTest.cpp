#include "EventHandlerTest.h"
#include "../IO/Output.h"

typedef void(*ptr)(GameStartEvent*);

Test Test::testTest{};

void Test::test(GameStartEvent* event)
{
}

Test::Test()
{
	testListener = CREATE_LISTENER(GameStartEvent, (ptr)test, 10);
}
