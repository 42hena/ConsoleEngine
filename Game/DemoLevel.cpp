#include "DemoLevel.h"

#include "TestActor.h"

#include <iostream>

DemoLevel::DemoLevel()
{
	std::cout << "[DemoLevel ����]\n";
	AddActor(new TestActor());
}

DemoLevel::~DemoLevel()
{
	std::cout << "[~DemoLevel �Ҹ�]\n";
}
