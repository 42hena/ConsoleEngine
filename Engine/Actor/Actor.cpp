#include "Actor.h"

#include <iostream>

/*
*		Ư�� �ɹ� �Լ�
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
*		�̺�Ʈ �Լ�
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