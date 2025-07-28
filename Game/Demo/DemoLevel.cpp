#include "DemoLevel.h"

#include "TestActor.h"

#include <iostream>

DemoLevel::DemoLevel()
{
	std::cout << "DemoLevel: " << DemoLevel::TypeIdClass() << "\n";
	std::cout << "[DemoLevel »ý¼º]\n";
	AddActor(new TestActor());
}

DemoLevel::~DemoLevel()
{
	std::cout << "[~DemoLevel ¼Ò¸ê]\n";
}
