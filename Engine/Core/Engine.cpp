#include "Engine.h"

#include <iostream>
#include <Windows.h>
#include <conio.h>

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
			Update(deltaTime);
			Render();

			previousTime = currentTime;
		}
	}
}

void Engine::Quit()
{
	// 종료 플레그 설정
	isQuit = true;
}

void Engine::ProcessInput()
{
	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
	{
		Quit();
	}
}

void Engine::Update(float deltaTime)
{
	std::cout << "DeltaTime: " << deltaTime << ", FPS: " << (1.0f / deltaTime) << "\n";
}

void Engine::Render()
{
}
