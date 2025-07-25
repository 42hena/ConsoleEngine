#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "Math/Vector2.h"
#include "RTTI.h"

class ENGINE_API Actor : public RTTI
{
	RTTI_DECLARATIONS(Actor, RTTI)

#pragma region 특수 맴버 함수
public:
	Actor();
	virtual ~Actor();
#pragma endregion

#pragma region 공개 함수
	/*
	*		이벤트 함수
	*/
	virtual void BeginPlay();				// 객체 생명주기에 1번만 호출(초기화 목적).
	virtual void Tick(float deltaTime = 0);	// 프레임마다 호출 (반복적 작업/지속성이 필요한 작업).
	virtual void Render();					// 그리기 함수.

	/*
	*		인라인 함수
	*/
	inline bool HasBeginPlay() const { return _hasBeginPlay; }
#pragma endregion

#pragma region 멤버 함수
private:
	Vector2 _position;
	char	_image = ' ';
	bool	_hasBeginPlay = false;
#pragma endregion
};

#endif
