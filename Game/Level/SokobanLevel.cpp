#include "SokobanLevel.h"

#include "Demo/TestActor.h"

#include "Math/Vector2.h"

#include "Actor/Player.h"
#include "Actor/Wall.h"
#include "Actor/Ground.h"
#include "Actor/Box.h"
#include "Actor/Target.h"

#include "Utils/Utils.h"

#include <iostream>

/*
*		Ư�� ��� �Լ�
*/

SokobanLevel::SokobanLevel()
{
	ReadMapFile("Stage1.txt");
}

/*
*		���� �Լ�
*/

/* �� ���� ���� �Լ� */
void SokobanLevel::ReadMapFile(const char* filename)
{
	// ���� ���� ��� �ϼ�
	char filePath[256];
	filePath[0] = '\0';
	sprintf_s(filePath, 256, "../Assets/%s", filename);

	FILE* pFile = nullptr;
	fopen_s(&pFile, filePath, "rt");
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
			continue;
		}

		switch (mapCharacter)
		{
		case '#':
		case '1':
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
			++_targetScore;
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

/* ���� ���� �Լ� */
bool SokobanLevel::CheckGameClear()
{
	int currentScore = 0;

	// target ���� 
	std::vector<Actor*>	targetActors;
	std::vector<Actor*>		boxActors;
	for (Actor*  pActor : _actors)
	{
		if (pActor->As<Target>()) {
			targetActors.emplace_back(pActor);	// ?????? 
		}
		else if (pActor->As<Target>())
		{
			boxActors.emplace_back(pActor);
		}
	}

	// �ڽ��� Ÿ�� ���� ��ġ ��
	for (Actor* const targetActor : targetActors)
	{
		for (Actor* const boxActor : boxActors)
		{
			if (targetActor->Position() == boxActor->Position()) {
				// ���� ����
				++currentScore;
			}
		}
	}

	return currentScore == _targetScore;
}

void SokobanLevel::Render()
{
	super::Render();
	//std::cout << "Hello\n";
	
	if (_isGameClear == true)
	{
		Utils::SetConsolePosition(COORD{ 30, 0 });
		Utils::SetConsoleTextColor(
			static_cast<WORD>(Color::Color_White)
		);
	}
}

bool SokobanLevel::CanPlayerMove(const Vector2& playerPosition, const Vector2& newPosition)
{
	if (_isGameClear == true) { 
		return false;
	}

	// �ڽ� ó��
	std::vector<Box*> boxActors;
	for (Actor* const actor : _actors)
	{
		Box* pBox = actor->As<Box>();
		if (pBox != nullptr) {
			boxActors.push_back(pBox);
		}
	}

	// �̵��Ϸ��� ��ġ�� �ڽ��� �ִ��� Ȯ��.
	Box* pSearchedBox = nullptr;
	for (Box* const pBoxActor : boxActors)
	{
		if (pBoxActor->Position() == newPosition)
		{
			pSearchedBox = pBoxActor;
			break;
		}
	}

	if (pSearchedBox != nullptr)
	{
		// case 1. �ڽ��� �� ��ǥ�� �ٸ� �ڽ��� �ִ� ���
		Vector2 newBoxPosition = newPosition + Vector2(newPosition - playerPosition);
		for (Box* const pOtherBox : boxActors)
		{
			if (pOtherBox == pSearchedBox)
			{
				continue;
			}// �߰��Ѱ� 
			if (pOtherBox->Position() == newBoxPosition) {
				return false;
			}
		}

		for (Actor* pActor : _actors)
		{
			// case 2. �ڽ� X, �� Ȯ��
			if (pActor->Position() == newBoxPosition)//������
			{
				if (pActor->As<Wall>()) {
					return false;
				}

				// case 3. �̵� ������ ���(��, Ÿ��)���� �ڽ� �̵� ó��
				if (pActor->As<Ground>() || pActor->As<Target>())
				{
					pSearchedBox->SetPosition(newBoxPosition);
					_isGameClear = CheckGameClear();
					return true;
				}
			}
		}

	}
	// �÷��̾ �̵��Ϸ��� ��ġ �� �ڽ��� ���� ���?
	for (Actor* const pActor : _actors)
	{
		if (pActor->Position() == newPosition)
		{
			// ���̸� �̵� �Ұ�
			if (pActor->As<Wall>()) {
				return false;
			}

			// �� or target
			return true;
		}
	}

	// ???
	return true;
}
