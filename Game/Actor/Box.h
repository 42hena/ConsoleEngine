#ifndef __BOX_H__
#define __BOX_H__

#include "Actor/Actor.h"

class Box : public Actor
{
	RTTI_DECLARATIONS(Box, Actor)

#pragma region 특수 멤버 함수
public:
	Box(const Vector2& position);
#pragma endregion
};

#endif
