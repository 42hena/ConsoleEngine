#ifndef __TARGET_H__
#define __TARGET_H__

#include "Actor/Actor.h"

class Target : public Actor
{
	RTTI_DECLARATIONS(Target, Actor)

#pragma region 특수 멤버 함수
public:
	Target(const Vector2& position);
#pragma endregion
};

#endif