#include "Actor.h"

#include <iostream>
#include <Windows.h>
#include "Utils/Utils.h"
/*
*		특수 맴버 함수
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
	// std::cout << "Actor 소멸 테스트:\n";
}

/*
*		이벤트 함수
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
	// 커서 위치 값 생성
	COORD coord;
	coord.X = static_cast<short>(_position._x);
	coord.Y = static_cast<short>(_position._y);
	
	// 커서 이동
	Utils::SetConsolePosition(coord);

	// 색상 변경
	Utils::SetConsoleTextColor(static_cast<WORD>(_color));

	// console 창 출력하여 그리기
	std::cout << _image;
}

void Actor::SetPosition(const Vector2& newPosition)
{
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	// 커서 위치 값 생성
	COORD coord;
	coord.X = static_cast<short>(_position._x);
	coord.Y = static_cast<short>(_position._y);

	// 커서 이동
	Utils::SetConsolePosition(coord);

	// console 창 출력하여 그리기
	std::cout << ' ';
	
	// 이동하려는 위치로 변경
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
