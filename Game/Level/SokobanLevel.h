#ifndef __SOKOBAN_LEVEL_H__
#define __SOKOBAN_LEVEL_H__

#include "Level/Level.h"

#include "Interface/ICanPlayerMove.h"

class SokobanLevel : public Level, public ICanPlayerMove
{
	RTTI_DECLARATIONS(SokobanLevel, Level)

#pragma region 특수 멤버 함수
public:
	SokobanLevel();
	~SokobanLevel(){}
#pragma endregion

#pragma region 공개 함수
private:
	/* 이벤트 함수 */
	virtual void Render() override;

public:
	/* 사용함수 */
	bool CanPlayerMove(const Vector2& playerPosition, const Vector2& newPosition) override;
#pragma endregion

#pragma region 내부 함수	
private:
	/* 파일 맵 관련 함수 */
	void ReadMapFile(const char* filename);

	/* 게임 로직 관련 함수*/
	bool CheckGameClear();
#pragma endregion

#pragma region 멤버 변수
	int		_targetScore = 0;
	bool	_isGameClear = false;
#pragma endregion
};

#endif
