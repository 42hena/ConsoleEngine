#include "Level.h"
#include "Actor/Actor.h"

#include <iostream>

/*
*		Ư�� ��� �Լ�
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
*		�̺�Ʈ �Լ�
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
*		��ü ���� �Լ�
*/

void Level::AddActor(Actor* newActor)
{
	_actors.push_back(newActor);
}
