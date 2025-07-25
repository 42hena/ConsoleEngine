#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "Math/Vector2.h"
#include "RTTI.h"

class ENGINE_API Actor : public RTTI
{
	RTTI_DECLARATIONS(Actor, RTTI)

#pragma region Ư�� �ɹ� �Լ�
public:
	Actor();
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
	*		�ζ��� �Լ�
	*/
	inline bool HasBeginPlay() const { return _hasBeginPlay; }
#pragma endregion

#pragma region ��� �Լ�
private:
	Vector2 _position;
	char	_image = ' ';
	bool	_hasBeginPlay = false;
#pragma endregion
};

#endif
