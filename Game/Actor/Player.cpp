#include "Player.h"
#include "Engine.h"

/*
*		Ư�� ��� �Լ�
*/

Player::Player(const Vector2& position)
	: Actor('P', Color::Color_Red, position)
{
	SetSortingOrder(3);
}

/*
*		�̺�Ʈ �Լ�
*/

void Player::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	// ESC Ű �Է�
	if (Input::GetInstance().GetKeyDown(VK_ESCAPE))
	{
		Engine::GetInstance().Quit();
		return;
	}

	// ����Ű �Է� ó��
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
