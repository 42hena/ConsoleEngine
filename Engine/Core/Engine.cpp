#include "Engine.h"

#include <iostream>
#include "Level/Level.h"

/*
*		특수 맴버 함수
*/

Engine::Engine()
{
}

Engine::~Engine()
{
	if (_mainLevel != nullptr)
	{
		delete _mainLevel;
		_mainLevel = nullptr;
	}
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

		ProcessInput();
		if (deltaTime >= oneFrameTime)
		{
			BeginPlay();
			Tick(deltaTime);
			Render();
			
			// 시간 업데이트
			previousTime = currentTime;

			// 현재 프레임의 입력을 기록
			for (int i = 0; i < 256; ++i)
			{
				_keyStates[i]._previousKeyDown = _keyStates[i]._isKeyDown;
			}
		}
	}
}

bool Engine::GetKey(int keyCode)
{
	return _keyStates[keyCode]._isKeyDown;
}

bool Engine::GetKeyDown(int keyCode)
{
	return !_keyStates[keyCode]._previousKeyDown && _keyStates[keyCode]._isKeyDown;
}

bool Engine::GetKeyUp(int keyCode)
{
	return _keyStates[keyCode]._previousKeyDown && !_keyStates[keyCode]._isKeyDown;
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

void Engine::ProcessInput()
{
	for (int i = 0; i < 255; ++i)
	{
		_keyStates[i]._isKeyDown = GetAsyncKeyState(i) & 0x8000;
	}

	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		Quit();
	}
}

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

	if (GetKeyDown(VK_ESCAPE))
	{
		Quit();
	}
	//std::cout << "DeltaTime: " << deltaTime << ", FPS: " << (1.0f / deltaTime) << "\n";
}

void Engine::Render()
{
	if (_mainLevel != nullptr)
	{
		_mainLevel->Render();
	}
}
