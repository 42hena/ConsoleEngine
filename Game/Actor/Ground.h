#pragma once
#ifndef __GROUND_H__
#define __GROUND_H__

#include "Actor/Actor.h"

class Ground : public Actor
{
	RTTI_DECLARATIONS(Ground, Actor)

#pragma region 특수 멤버 함수
public:
	Ground(const Vector2& position);
#pragma endregion
};

#endif
