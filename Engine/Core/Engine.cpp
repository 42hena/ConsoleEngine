#include "Engine.h"

#include <iostream>
#include "Level/Level.h"

/*
*		Ư�� �ɹ� �Լ�
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
*		���� �Լ�
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
			
			// �ð� ������Ʈ
			previousTime = currentTime;

			// ���� �������� �Է��� ���
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
	// ���� �÷��� ����
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
*		Engine�� ���� �Լ�
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
