#ifndef __TEST_ACTOR_H__
#define __TEST_ACTOR_H__

#include "Actor/Actor.h"

class TestActor : public Actor
{
#pragma region Ư�� ��� �Լ�
public:
	TestActor();
	virtual ~TestActor()				override;
#pragma endregion

#pragma region	�̺�Ʈ �Լ�
public:
	virtual void Tick(float deltaTime)	override;
#pragma endregion
};

#endif // __TEST_ACTOR_H__
