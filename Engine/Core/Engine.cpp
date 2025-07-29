#include "Engine.h"

#include "Level/Level.h"

#include "Utils/Utils.h"

#include "Input.h"

#include <iostream>
#include <Windows.h>

/*
*		static 변수 초기화
*/

Engine* Engine::_static_instance = nullptr;

BOOL /*WINAPI*/ ConsoleMessageProcedure(DWORD ctrlType)
{
	switch (ctrlType)
	{
	case CTRL_CLOSE_EVENT:
		Engine::GetInstance().CleanUp();
		return false;
	default:
		break;
	}
	return false;
}

/*
*		특수 맴버 함수
*/

Engine::Engine()
{
	_static_instance = this;

	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 1;// 찾아보기

	// 콘솔 커서 끄기
	
	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&info
	);

	SetConsoleCtrlHandler(ConsoleMessageProcedure, true);
	// 모든 텍스트 색상이 변경.
	/*SetConsoleTextAttribute(
		GetStdHandle(STD_OUTPUT_HANDLE),
		FOREGROUND_GREEN
	);*/
}

Engine::~Engine()
{
	if (false)
		CleanUp();
}

/*
*		클래스 내부 static 함수
*/

Engine& Engine::GetInstance()
{
	return *_static_instance;
}

/*
*		공개 함수
*/

void Engine::Run()
{
	LARGE_INTEGER currentTime;
	LARGE_INTEGER previousTime;
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&currentTime);
	previousTime = currentTime;
	printf("%lld %lld\n", currentTime.QuadPart, frequency.QuadPart);

	float targetFrameRate = 60.0f;
	float oneFrameTime = 1.0f / targetFrameRate;

	long long times;
	while (!isQuit)
	{
		QueryPerformanceCounter(&currentTime);
		times = currentTime.QuadPart - previousTime.QuadPart;
		float deltaTime = times / (float)frequency.QuadPart;

		_input.ProcessInput();
		if (deltaTime >= oneFrameTime)
		{
			BeginPlay();
			Tick(deltaTime);
			Render();
			
			// 시간 업데이트
			previousTime = currentTime;

			// 현재 프레임의 입력을 기록
			_input.SavePreviousKeyStates();
		}
	}

	// Console 출력 색 원래대로 변경
	Utils::SetConsoleTextColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

void Engine::CleanUp()
{
	SafeDelete(_mainLevel);
	std::cout << "Engine 삭제\n";
}

void Engine::Quit()
{
	// 종료 플레그 설정
	isQuit = true;
}

void Engine::AddLevel(Level* newLevel)
{
	if (_mainLevel != nullptr)
	{
		delete _mainLevel;
		_mainLevel = nullptr;
	}
	_mainLevel = newLevel;
}

/*
*		Engine의 내부 함수
*/

void Engine::BeginPlay()
{
	if (_mainLevel != nullptr)
	{
		_mainLevel->BeginPlay();
	}
}

void Engine::Tick(float deltaTime)
{
	/*if (GetKeyDown('A'))
	{
		std::cout << "GetKeyDown('a')\n";
	}
	if (GetKey('A'))
	{
		std::cout << "GetKey('a')\n";
	}

	if (GetKeyUp('A'))
	{
		std::cout << "GetKeyUp('a')\n";
	}*/
	
	if (_mainLevel != nullptr)
	{
		_mainLevel->Tick(deltaTime);
	}

	/*if (GetKeyDown(VK_ESCAPE))
	{
		Quit();
	}*/
	//std::cout << "DeltaTime: " << deltaTime << ", FPS: " << (1.0f / deltaTime) << "\n";
}

void Engine::Render()
{
	// Console 출력 색 변경
	Utils::SetConsoleTextColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

	if (_mainLevel != nullptr)
	{
		_mainLevel->Render();
	}
}
