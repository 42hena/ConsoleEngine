#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "Core.h"
#include <Windows.h>

class ENGINE_API Engine
{
#pragma region 특수 맴버 함수
public:
	Engine()							= default;
	~Engine()							= default;

public:
	Engine(const Engine&)				= delete;
	Engine& operator=(const Engine&)	= delete;
	Engine(Engine&&)					= delete;
	Engine& operator=(Engine&&)			= delete;
#pragma endregion

#pragma region 공개 함수
public:
	// 엔진 실행 함수
	void Run();

	// 엔진 종료 함수
	void Quit();
#pragma endregion

#pragma region 내부 함수
private:
	void ProcessInput();
	void Update(float deltaTime = 0.0f);
	void Render();
#pragma endregion

#pragma region 맴버 변수
private:
	bool isQuit = false;
#pragma endregion
};

#endif
