#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "Math/Vector2.h"
#include "RTTI.h"

// ����
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
	RTTI_DECLARATIONS(Actor, RTTI)

#pragma region Ư�� �ɹ� �Լ�
public:
	// Actor() = delete;
	Actor(const char image = ' ', Color color = Color::Color_White);
	virtual ~Actor();
#pragma endregion

#pragma region ���� �Լ�
	/*
	*		�̺�Ʈ �Լ�
	*/
	virtual void BeginPlay();				// ��ü �����ֱ⿡ 1���� ȣ��(�ʱ�ȭ ����).
	virtual void Tick(float deltaTime = 0);	// �����Ӹ��� ȣ�� (�ݺ��� �۾�/���Ӽ��� �ʿ��� �۾�).
	virtual void Render();					// �׸��� �Լ�.

	/*
	*		�Ϲ� �Լ�
	*/
	void SetPosition(const Vector2& newPosition);
	Vector2 Position() const;

	/*
	*		�ζ��� �Լ�
	*/
	inline bool HasBeginPlay() const { return _hasBeginPlay; }
#pragma endregion

#pragma region ��� ����
private:
	Vector2 _position;
	char	_image = ' ';
	bool	_hasBeginPlay = false;

	Color _color;
#pragma endregion
};

#endif
