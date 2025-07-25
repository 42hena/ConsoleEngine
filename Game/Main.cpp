#include <iostream>
#include "Engine.h"
#include "Math/Vector2.h"
#include "DemoLevel.h"
#include <Windows.h>
#define _CRTDBG_MAP_ALLOC

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	Engine engine;
	engine.AddLevel(new DemoLevel());
	engine.Run();
}
