#include "DemoLevel.h"

#include "TestActor.h"

#include <iostream>

DemoLevel::DemoLevel()
{
	std::cout << "DemoLevel: " << DemoLevel::TypeIdClass() << "\n";
	std::cout << "[DemoLevel 생성]\n";
	AddActor(new TestActor());

	FILE* pFile = nullptr;
	fopen_s(&pFile, "../Assets/Map.txt", "rb");

	// 예외 처리
	if (pFile == nullptr)
	{
		std::cout << "Failed to open Map.txt file\n";
		__debugbreak();
		return;
	}

	// 파일 크기 확인
	fseek(pFile, 0, SEEK_END);
	int endPos = ftell(pFile);
	int fileSize = 0;
	fseek(pFile, 0, SEEK_SET);
	fileSize = endPos;
	std::cout << "File Size: " << fileSize << "\n";

	// 데이터 저장을 위한 버퍼 할당.
	char buffer[256];
	while (!feof(pFile))
	{
		char * pBuffer = fgets(buffer, 256, pFile);
		if (pBuffer == nullptr)
			break;
		int lineLength = static_cast<int>(strlen(buffer));

		int a = 0;
		
		for (int idx = 0; idx < lineLength; ++idx)
		{
			char mapCharacter = pBuffer[idx];
			
			switch (mapCharacter)
			{
			case '#':
				std::cout << "#";
				break;
			case '.':
				std::cout << ".";
				break;
			case ' ':
				std::cout << " ";
				break;
			case 'p':
				std::cout << "p";
				break;
			case 'b':
				std::cout << "b";
				break;
			case 't':
				std::cout << "t";
				break;
			case '\n':
				std::cout << "\n";
				break;
			default:
				break;
			}
		}
	}
// 파일 닫기
	fclose(pFile);

}

DemoLevel::~DemoLevel()
{
	std::cout << "[~DemoLevel 소멸]\n";
}
