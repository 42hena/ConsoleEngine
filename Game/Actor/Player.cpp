#include "Player.h"
#include "Engine.h"

#include "Interface/ICanPlayermove.h"

#include "Level/Level.h"

#include "Game/Game.h"

#include <iostream>

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

void Player::BeginPlay()
{
	super::BeginPlay();

	Level* owner = GetOnwer();
	if (owner != nullptr)
	{
		_canPlayerMoveInterface = dynamic_cast<ICanPlayerMove*>(owner);

		if (_canPlayerMoveInterface != nullptr) {
			std::cout << "ICanPlayerMove�� dynamic_cast ����\n";
		}
	}
}

void Player::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	// ESC Ű �Է�
	if (Input::GetInstance().GetKeyDown(VK_ESCAPE))
	{
		Game::GetInstance().ToggleMenu();
		return;
	}

	// �̵� ����

	// ����Ű �Է� ó��
	if (Input::GetInstance().GetKeyDown(VK_RIGHT))
	{ 
		Vector2 newPosition = Position();
		newPosition._x += 1;
		if (_canPlayerMoveInterface->CanPlayerMove(Position(), newPosition))
		{
			SetPosition(newPosition);
		}
	}
	if (Input::GetInstance().GetKeyDown(VK_LEFT))
	{ 
		Vector2 newPosition = Position();
		newPosition._x -= 1;

		bool result = _canPlayerMoveInterface->CanPlayerMove(Position(), newPosition);
		if (result == true) {
			SetPosition(newPosition);
		}
	}
	if (Input::GetInstance().GetKeyDown(VK_UP))
	{
		Vector2 newPosition = Position();
		newPosition._y -= 1;
		bool result = _canPlayerMoveInterface->CanPlayerMove(Position(), newPosition);
		if (result == true) {
			SetPosition(newPosition);
		}
	}
	if (Input::GetInstance().GetKeyDown(VK_DOWN))
	{
		Vector2 newPosition = Position();
		newPosition._y += 1;
		bool result = _canPlayerMoveInterface->CanPlayerMove(Position(), newPosition);
		if (result == true) {
			SetPosition(newPosition);
		}
	}
}
