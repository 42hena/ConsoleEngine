#include "Actor.h"

#include <iostream>

/*
*		특수 맴버 함수
*/
Actor::Actor()
	: _hasBeginPlay(false)
{
	std::cout << "Actor: " << Actor::TypeIdClass() << "\n";
}

Actor::~Actor()
{
}

/*
*		이벤트 함수
*/

void Actor::BeginPlay()
{
	_hasBeginPlay = true;
}

void Actor::Tick(float deltaTime)
{
}

void Actor::Render()
{
}