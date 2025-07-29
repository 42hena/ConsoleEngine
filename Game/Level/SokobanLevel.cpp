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
*		특수 멤버 함수
*/

SokobanLevel::SokobanLevel()
{
	ReadMapFile("Stage1.txt");
}

/*
*		내부 함수
*/

/* 맵 파일 관련 함수 */
void SokobanLevel::ReadMapFile(const char* filename)
{
	// 최종 에셋 경로 완성
	char filePath[256];
	filePath[0] = '\0';
	sprintf_s(filePath, 256, "../Assets/%s", filename);

	FILE* pFile = nullptr;
	fopen_s(&pFile, filePath, "rt");
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

	// 버퍼 해제
	delete[] buffer;

	fclose(pFile);
}

/* 게임 관련 함수 */
bool SokobanLevel::CheckGameClear()
{
	int currentScore = 0;

	// target 엑터 
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

	// 박스와 타겟 액터 위치 비교
	for (Actor* const targetActor : targetActors)
	{
		for (Actor* const boxActor : boxActors)
		{
			if (targetActor->Position() == boxActor->Position()) {
				// 점수 증가
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

	// 박스 처리
	std::vector<Box*> boxActors;
	for (Actor* const actor : _actors)
	{
		Box* pBox = actor->As<Box>();
		if (pBox != nullptr) {
			boxActors.push_back(pBox);
		}
	}

	// 이동하려는 위치에 박스가 있는지 확인.
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
		// case 1. 박스의 새 좌표에 다른 박스가 있는 경우
		Vector2 newBoxPosition = newPosition + Vector2(newPosition - playerPosition);
		for (Box* const pOtherBox : boxActors)
		{
			if (pOtherBox == pSearchedBox)
			{
				continue;
			}// 추가한거 
			if (pOtherBox->Position() == newBoxPosition) {
				return false;
			}
		}

		for (Actor* pActor : _actors)
		{
			// case 2. 박스 X, 벽 확인
			if (pActor->Position() == newBoxPosition)//문제점
			{
				if (pActor->As<Wall>()) {
					return false;
				}

				// case 3. 이동 가능한 경우(땅, 타겟)에는 박스 이동 처리
				if (pActor->As<Ground>() || pActor->As<Target>())
				{
					pSearchedBox->SetPosition(newBoxPosition);
					_isGameClear = CheckGameClear();
					return true;
				}
			}
		}

	}
	// 플레이어가 이동하려는 위치 에 박스가 없는 경우?
	for (Actor* const pActor : _actors)
	{
		if (pActor->Position() == newPosition)
		{
			// 벽이면 이동 불가
			if (pActor->As<Wall>()) {
				return false;
			}

			// 땅 or target
			return true;
		}
	}

	// ???
	return true;
}
