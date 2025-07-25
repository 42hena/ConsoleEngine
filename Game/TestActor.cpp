#include "TestActor.h"

#include <iostream>

/*
*		특수 멤버 함수
*/

TestActor::TestActor()
{
	std::cout << "[TestActor 생성]\n";
	std::cout << "TestActor: " << TestActor::TypeIdClass() << "\n";

}

TestActor::~TestActor()
{
	std::cout << "[~TestActor 소멸]\n";
}

/*
*		이벤트 함수
*/

void TestActor::Tick(float deltaTime)
{
	// Actor::Tick(deltaTime);
	super::Tick(deltaTime);

	std::cout << "TestActor::Tick. FPS: " << (1.0f / deltaTime) << "\n";
}
