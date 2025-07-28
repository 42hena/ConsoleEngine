#pragma once
#ifndef __WALL_H__
#define __WALL_H__

#include "Actor/Actor.h"

class Wall : public Actor
{
	RTTI_DECLARATIONS(Wall, Actor)

#pragma region 특수 멤버 함수
public:
	Wall(const Vector2& position);
#pragma endregion
};

#endif
