#include "Target.h"

/*
*		Ư�� ��� �Լ�
*/

Target::Target(const Vector2& position)
	: Actor('T', Color::Color_Blue, position)
{
	SetSortingOrder(1);
}
