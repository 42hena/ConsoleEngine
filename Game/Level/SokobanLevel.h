#ifndef __SOKOBAN_LEVEL_H__
#define __SOKOBAN_LEVEL_H__

#include "Level/Level.h"

#include "Interface/ICanPlayerMove.h"

class SokobanLevel : public Level, public ICanPlayerMove
{
	RTTI_DECLARATIONS(SokobanLevel, Level)

#pragma region Ư�� ��� �Լ�
public:
	SokobanLevel();
	~SokobanLevel(){}
#pragma endregion

#pragma region ���� �Լ�
private:
	/* �̺�Ʈ �Լ� */
	virtual void Render() override;

public:
	/* ����Լ� */
	bool CanPlayerMove(const Vector2& playerPosition, const Vector2& newPosition) override;
#pragma endregion

#pragma region ���� �Լ�	
private:
	/* ���� �� ���� �Լ� */
	void ReadMapFile(const char* filename);

	/* ���� ���� ���� �Լ�*/
	bool CheckGameClear();
#pragma endregion

#pragma region ��� ����
	int		_targetScore = 0;
	bool	_isGameClear = false;
#pragma endregion
};

#endif
