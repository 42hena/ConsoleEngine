#include "SokobanLevel.h"

#include "Demo/TestActor.h"

#include "Math/Vector2.h"

#include "Actor/Player.h"
#include "Actor/Wall.h"
#include "Actor/Ground.h"
#include "Actor/Box.h"
#include "Actor/Target.h"

#include <iostream>

/*
*		특수 멤버 함수
*/

SokobanLevel::SokobanLevel()
{
	ReadMapFile("Map.txt");
}

/*
*		내부 함수
*/

void SokobanLevel::ReadMapFile(const char* filename)
{
	// 최종 에셋 경로 완성
	char filePath[256];
	filePath[0] = '\0';
	sprintf_s(filePath, 256, "../Assets/%s", filename);

	FILE* pFile = nullptr;
	fopen_s(&pFile, filePath, "rb");
	if (pFile == nullptr)
	{
		std::cout << "맵 파일 읽기 실패:" << filePath << ' ' << filename << "\n";
		__debugbreak();
	}

	// 파싱(Parcing, 해석)
	fseek(pFile, 0, SEEK_END);
	size_t fileSize = ftell(pFile);
	rewind(pFile);

	char* buffer = new char[fileSize + 1];
	size_t readSize = fread(buffer, sizeof(char), fileSize, pFile);
	buffer[fileSize] = '\0';

	if (fileSize != readSize) {
		std::cout << "파일 사이즈가 매칭되지 않았어\n";
	}

	// 배열 순회를 위한 인덱스 변후
	int index = 0;
	// 문자열 길이 값
	int size = static_cast<int>(readSize);
	
	//
	Vector2 position;


	while (index < size)
	{
		// 맵 문자 확인
		char mapCharacter = buffer[index]; 
		++index;
		if (mapCharacter == '\n')
		{
			++position._y;
			position._x = 0;
			std::cout << "\n";
			continue;
		}

		switch (mapCharacter)
		{
		case '#':
			AddActor(new Wall(position));
			break;
		case '.':
			AddActor(new Ground(position));
			break;
		case 'p':
			AddActor(new Ground(position));
			AddActor(new Player(position));
			break;
		case 'b':
			AddActor(new Ground(position));
			AddActor(new Box(position));
			break;
		case 't':
			AddActor(new Target(position));
			break;
		default:
			break;
		}
		++position._x;
	}

	// 버퍼 해제
	delete[] buffer;

	fclose(pFile);
}
