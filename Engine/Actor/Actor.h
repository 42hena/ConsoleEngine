#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "Math/Vector2.h"
#include "RTTI.h"

// 색상
enum class Color : int
{
	Color_Blue		= 1,
	Color_Green		= 2,
	Color_Red		= 4,
	Color_White		= Color_Blue | Color_Green | Color_Red,
	Color_Intensity = 8,
};

class ENGINE_API Actor : public RTTI
{
	friend class Level;
	RTTI_DECLARATIONS(Actor, RTTI)

#pragma region 특수 맴버 함수
public:
	Actor(const char image = ' ', Color color = Color::Color_White, const Vector2& position = Vector2::Zero);
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
	*		일반 함수
	*/
	void SetPosition(const Vector2& newPosition);
	Vector2 Position() const;

	void SetSortingOrder(unsigned int sortingOrder);
	
	/*
	*		인라인 함수
	*/
	inline bool HasBeginPlay() const { return _hasBeginPlay; }
#pragma endregion

#pragma region 멤버 변수
private:
	Vector2 _position;
	char	_image = ' ';
	bool	_hasBeginPlay = false;
	Color	_color;
	unsigned int _sortingOrder = 0;
#pragma endregion
};

#endif
