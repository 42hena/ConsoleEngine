#include "Player.h"
#include "Engine.h"

/*
*		특수 멤버 함수
*/

Player::Player(const Vector2& position)
	: Actor('P', Color::Color_Red, position)
{
	SetSortingOrder(3);
}

/*
*		이벤트 함수
*/

void Player::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	// ESC 키 입력
	if (Input::GetInstance().GetKeyDown(VK_ESCAPE))
	{
		Engine::GetInstance().Quit();
		return;
	}

	// 방향키 입력 처리
	if (Input::GetInstance().GetKeyDown(VK_RIGHT))
	{ 
		Vector2 position = Position();
		position._x += 1;
		SetPosition(position);
	}
	if (Input::GetInstance().GetKeyDown(VK_LEFT))
	{ 
		Vector2 position = Position();
		position._x -= 1;
		SetPosition(position);
	}
	if (Input::GetInstance().GetKeyDown(VK_UP))
	{
		Vector2 position = Position();
		position._y -= 1;
		SetPosition(position);
	}
	if (Input::GetInstance().GetKeyDown(VK_DOWN))
	{
		Vector2 position = Position();
		position._y += 1;
		SetPosition(position);
	}
}
