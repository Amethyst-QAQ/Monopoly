#include "Listener.h"
#include "Events/AllEvents.h"

class GameStartEvent;

class Test
{
public:
	Listener *testListener;
	static void test(GameStartEvent* event);
	Test();
	~Test() { delete testListener; }
	static Test testTest;
};