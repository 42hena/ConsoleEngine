#include "Actor.h"

/*
*		특수 맴버 함수
*/

Actor::Actor()
	: _hasBeginPlay(false)
{
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