#include "Level.h"
#include "Actor/Actor.h"

#include <iostream>

/*
*		특수 멤버 함수
*/

Level::Level()
{
	// std::cout << "Level: " << Level::TypeIdClass() << "\n";
}

Level::~Level()
{
	for (const Actor* actor : _actors)	{
		SafeDelete(actor);
	}
	_actors.clear();
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
	// 정렬해서 재배치
	SortActorsBySortingOrder();

	// RenderPass
	for (Actor* const actor : _actors) {
		Actor* searchActor = nullptr;
		for (Actor* const otherActors : _actors)
		{
			if (actor == otherActors) { 
				continue; 
			}

			if (actor->Position() == otherActors->Position())
			{
				if (actor->_sortingOrder < otherActors->_sortingOrder)
				{
					searchActor = otherActors;
					break;
				}
			}
		}

		if (searchActor != nullptr) { 
			continue; 
		}

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

/*
*		내부 함수
*/

void Level::SortActorsBySortingOrder()
{
	for (int idx = 0; idx < static_cast<int>(_actors.size()); ++idx)
	{
		for (int j = 0; j < static_cast<int>(_actors.size()) - 1 ; ++j)
		{
			if (_actors[j]->_sortingOrder > _actors[j + 1]->_sortingOrder)
			{
				std::swap(_actors[j], _actors[j + 1]);
			}
		}
	}
}
