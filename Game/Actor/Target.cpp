#include "Target.h"

/*
*		특수 멤버 함수
*/

Target::Target(const Vector2& position)
	: Actor('T', Color::Color_Blue, position)
{
	SetSortingOrder(1);
}
