#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Actor/Actor.h"

class Player : public Actor
{
	RTTI_DECLARATIONS(Player, Actor)

#pragma region Ư�� ��� �Լ�
public:
	Player(const Vector2& position);
#pragma endregion

#pragma region �̺�Ʈ �Լ�
public:
	virtual void Tick(float deltaTime) override;
#pragma endregion
};

#endif
