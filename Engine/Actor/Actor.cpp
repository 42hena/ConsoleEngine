#include "Actor.h"

#include <iostream>
#include <Windows.h>
#include "Utils/Utils.h"
/*
*		Ư�� �ɹ� �Լ�
*/
Actor::Actor(const char image, Color color, const Vector2& position)
	: _hasBeginPlay(false),
	_image(image),
	_color(color),
	_position(position),
	_sortingOrder(0)
{
	// std::cout << "Actor: " << Actor::TypeIdClass() << "\n";
}

Actor::~Actor()
{
	// std::cout << "Actor �Ҹ� �׽�Ʈ:\n";
}

/*
*		�̺�Ʈ �Լ�
*/

void Actor::BeginPlay()
{
	_hasBeginPlay = true;
}

void Actor::Tick(float deltaTime)
{
}

void Actor::Render()
{
	// Ŀ�� ��ġ �� ����
	COORD coord;
	coord.X = static_cast<short>(_position._x);
	coord.Y = static_cast<short>(_position._y);
	
	// Ŀ�� �̵�
	Utils::SetConsolePosition(coord);

	// ���� ����
	Utils::SetConsoleTextColor(static_cast<WORD>(_color));

	// console â ����Ͽ� �׸���
	std::cout << _image;
}

void Actor::SetPosition(const Vector2& newPosition)
{
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	// Ŀ�� ��ġ �� ����
	COORD coord;
	coord.X = static_cast<short>(_position._x);
	coord.Y = static_cast<short>(_position._y);

	// Ŀ�� �̵�
	Utils::SetConsolePosition(coord);

	// console â ����Ͽ� �׸���
	std::cout << ' ';
	
	// �̵��Ϸ��� ��ġ�� ����
	_position = newPosition;
}

Vector2 Actor::Position() const
{
	return _position;
}

void Actor::SetSortingOrder(unsigned int sortingOrder)
{
	_sortingOrder = sortingOrder;
}
