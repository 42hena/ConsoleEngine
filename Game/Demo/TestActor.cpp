#include "TestActor.h"

#include "Engine.h"

#include <iostream>
#include <Windows.h>

/*
*		특수 멤버 함수
*/

TestActor::TestActor()
	:Actor('p', Color::Color_Red)
{
	std::cout << "[TestActor 생성]\n";
	std::cout << "TestActor: " << TestActor::TypeIdClass() << "\n";

}

TestActor::~TestActor()
{
	std::cout << "[~TestActor 소멸]\n";
}

/*
*		이벤트 함수
*/

void TestActor::Tick(float deltaTime)
{
	// Actor::Tick(deltaTime);
	super::Tick(deltaTime);

	// std::cout << "TestActor::Tick. FPS: " << (1.0f / deltaTime) << "\n";
	if (Engine::GetInstance().GetKeyDown(VK_RIGHT) && (Position()._x < 30))
	{
		Vector2 position = Position();
		position._x += 1;
		SetPosition(position);
	}

	if (Engine::GetInstance().GetKeyDown(VK_LEFT) && (Position()._x > 0))
	{
		Vector2 position = Position();
		position._x -= 1;
		SetPosition(position);
	}

	if (Engine::GetInstance().GetKeyDown(VK_UP) && (Position()._y > 0))
	{
		Vector2 position = Position();
		position._y -= 1;
		SetPosition(position);
	}

	if (Engine::GetInstance().GetKeyDown(VK_DOWN) && (Position()._y < 20))
	{
		Vector2 position = Position();
		position._y += 1;
		SetPosition(position);
	}

	if (Engine::GetInstance().GetKeyDown(VK_ESCAPE))
	{
		Engine::GetInstance().Quit();
	}
}
