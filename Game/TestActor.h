#ifndef __TEST_ACTOR_H__
#define __TEST_ACTOR_H__

#include "Actor/Actor.h"

class TestActor : public Actor
{
#pragma region 특수 멤버 함수
public:
	TestActor();
	virtual ~TestActor()				override;
#pragma endregion

#pragma region	이벤트 함수
public:
	virtual void Tick(float deltaTime)	override;
#pragma endregion
};

#endif // __TEST_ACTOR_H__
