#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "Core.h"
#include "Input.h"
#include <Windows.h>

class Level;
class ENGINE_API Engine
{
#pragma region 특수 맴버 함수
public:
	Engine();
	~Engine();

public:
	Engine(const Engine&)				= delete;
	Engine& operator=(const Engine&)	= delete;
	Engine(Engine&&)					= delete;
	Engine& operator=(Engine&&)			= delete;
#pragma endregion
	
#pragma region 클래스 내부 static 함수
public:
	static Engine& GetInstance();
#pragma endregion

#pragma region 공개 함수
public:
	// 엔진 실행 함수
	void Run();

	

	// 엔진 종료 함수
	void CleanUp();
	void Quit();

	void AddLevel(Level* newLevel);

#pragma endregion

#pragma region 내부 함수
private:
	void BeginPlay();
	void Tick(float deltaTime = 0.0f);
	void Render();
#pragma endregion

#pragma region static 변수
private:
	static Engine* _static_instance;
#pragma endregion

#pragma region 맴버 변수
private:
	bool isQuit = false;
	Level* _mainLevel = nullptr;
	Input _input;
#pragma endregion
};

#endif
