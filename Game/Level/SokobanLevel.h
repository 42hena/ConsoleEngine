#ifndef __SOKOBAN_LEVEL_H__
#define __SOKOBAN_LEVEL_H__

#include "Level/Level.h"

class SokobanLevel : public Level
{
	RTTI_DECLARATIONS(SokobanLevel, Level)

#pragma region Ư�� ��� �Լ�
public:
	SokobanLevel();
#pragma endregion

#pragma region ���� �Լ�	
private:
	void ReadMapFile(const char* filename);
#pragma endregion
};

#endif
