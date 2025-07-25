#include "Level.h"
#include "Actor/Actor.h"

#include <iostream>

/*
*		특수 멤버 함수
*/
Level::Level()
{
	std::cout << "Level: " << Level::TypeIdClass() << "\n";
}

Level::~Level()
{
	for (Actor* const actor : _actors)	{
		delete actor;
	}
}

/*
*		이벤트 함수
*/

void Level::BeginPlay()
{
	for (Actor* const actor : _actors)
	{
		if (actor->HasBeginPlay() == true) { continue; }

		actor->BeginPlay();
	}
}

void Level::Tick(float deltaTime)
{
	for (Actor* const actor : _actors) {
		actor->Tick(deltaTime);
	}
}

void Level::Render()
{
	for (Actor* const actor : _actors) {
		actor->Render();
	}
}

/*
*		객체 관리 함수
*/

void Level::AddActor(Actor* newActor)
{
	_actors.push_back(newActor);
}
