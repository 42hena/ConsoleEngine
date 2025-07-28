#include "Box.h"

/*
*		특수 멤버 함수
*/

Box::Box(const Vector2& position)
	: Actor('B', Color::Color_Green, position)
{
	SetSortingOrder(2);
}
