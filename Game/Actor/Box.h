#ifndef __BOX_H__
#define __BOX_H__

#include "Actor/Actor.h"

class Box : public Actor
{
	RTTI_DECLARATIONS(Box, Actor)

#pragma region Ư�� ��� �Լ�
public:
	Box(const Vector2& position);
#pragma endregion
};

#endif
