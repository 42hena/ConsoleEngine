#ifndef __SOKOBAN_LEVEL_H__
#define __SOKOBAN_LEVEL_H__

#include "Level/Level.h"

class SokobanLevel : public Level
{
	RTTI_DECLARATIONS(SokobanLevel, Level)

#pragma region 특수 멤버 함수
public:
	SokobanLevel();
#pragma endregion

#pragma region 내부 함수	
private:
	void ReadMapFile(const char* filename);
#pragma endregion
};

#endif
