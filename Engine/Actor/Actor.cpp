#include "Actor.h"

/*
*		Ư�� �ɹ� �Լ�
*/

Actor::Actor()
	: _hasBeginPlay(false)
{
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