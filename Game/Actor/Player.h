#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Actor/Actor.h"

class Player : public Actor
{
	RTTI_DECLARATIONS(Player, Actor)

#pragma region 특수 멤버 함수
public:
	Player(const Vector2& position);
#pragma endregion

#pragma region 이벤트 함수
public:
	virtual void Tick(float deltaTime) override;
#pragma endregion
};

#endif
