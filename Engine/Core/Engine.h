#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "Core.h"
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
	
#pragma region KeyState_키_확인_구조체
	struct KeyState
	{
		enum CONST_KEYSTATE
		{
			VK_MAX = 255
		};
		bool _isKeyDown = false;
		bool _previousKeyDown = false;
	};
#pragma endregion

#pragma region 공개 함수
public:
	// 엔진 실행 함수
	void Run();

	// 키 확인 함수
	bool GetKey(int keyCode);
	bool GetKeyDown(int keyCode);
	bool GetKeyUp(int keyCode);

	// 엔진 종료 함수
	void Quit();

	void AddLevel(Level* newLevel);

#pragma endregion

#pragma region 내부 함수
private:
	void ProcessInput();

	void BeginPlay();
	void Tick(float deltaTime = 0.0f);
	void Render();
#pragma endregion

#pragma region 맴버 변수
private:
	bool isQuit = false;
	KeyState _keyStates[256];
	Level* _mainLevel = nullptr;
#pragma endregion
};

#endif
