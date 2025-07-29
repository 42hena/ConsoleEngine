#include <iostream>
#include "Engine.h"
#include "Math/Vector2.h"
#include "Demo/DemoLevel.h"
#include "Level/SokobanLevel.h"
#include "Level/MenuLevel.h"
#include "Game/Game.h"
#include <Windows.h>
#define _CRTDBG_MAP_ALLOC
using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Game sokobanGame;
	SokobanLevel* pNew = new SokobanLevel();
	sokobanGame.Run();
}
