#include "Box.h"

/*
*		Ư�� ��� �Լ�
*/

Box::Box(const Vector2& position)
	: Actor('B', Color::Color_Green, position)
{
	SetSortingOrder(2);
}
