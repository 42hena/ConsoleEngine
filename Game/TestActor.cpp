#include "TestActor.h"

#include <iostream>

/*
*		Ư�� ��� �Լ�
*/

TestActor::TestActor()
{
	std::cout << "[TestActor ����]\n";
	std::cout << "TestActor: " << TestActor::TypeIdClass() << "\n";

}

TestActor::~TestActor()
{
	std::cout << "[~TestActor �Ҹ�]\n";
}

/*
*		�̺�Ʈ �Լ�
*/

void TestActor::Tick(float deltaTime)
{
	// Actor::Tick(deltaTime);
	super::Tick(deltaTime);

	std::cout << "TestActor::Tick. FPS: " << (1.0f / deltaTime) << "\n";
}
