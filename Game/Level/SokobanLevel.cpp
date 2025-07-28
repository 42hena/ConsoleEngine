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
*		Ư�� ��� �Լ�
*/

SokobanLevel::SokobanLevel()
{
	ReadMapFile("Map.txt");
}

/*
*		���� �Լ�
*/

void SokobanLevel::ReadMapFile(const char* filename)
{
	// ���� ���� ��� �ϼ�
	char filePath[256];
	filePath[0] = '\0';
	sprintf_s(filePath, 256, "../Assets/%s", filename);

	FILE* pFile = nullptr;
	fopen_s(&pFile, filePath, "rb");
	if (pFile == nullptr)
	{
		std::cout << "�� ���� �б� ����:" << filePath << ' ' << filename << "\n";
		__debugbreak();
	}

	// �Ľ�(Parcing, �ؼ�)
	fseek(pFile, 0, SEEK_END);
	size_t fileSize = ftell(pFile);
	rewind(pFile);

	char* buffer = new char[fileSize + 1];
	size_t readSize = fread(buffer, sizeof(char), fileSize, pFile);
	buffer[fileSize] = '\0';

	if (fileSize != readSize) {
		std::cout << "���� ����� ��Ī���� �ʾҾ�\n";
	}

	// �迭 ��ȸ�� ���� �ε��� ����
	int index = 0;
	// ���ڿ� ���� ��
	int size = static_cast<int>(readSize);
	
	//
	Vector2 position;


	while (index < size)
	{
		// �� ���� Ȯ��
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

	// ���� ����
	delete[] buffer;

	fclose(pFile);
}
