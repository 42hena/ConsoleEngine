#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "Core.h"
#include <Windows.h>

class Level;
class ENGINE_API Engine
{
#pragma region Ư�� �ɹ� �Լ�
public:
	Engine();
	~Engine();

public:
	Engine(const Engine&)				= delete;
	Engine& operator=(const Engine&)	= delete;
	Engine(Engine&&)					= delete;
	Engine& operator=(Engine&&)			= delete;
#pragma endregion
	
#pragma region KeyState_Ű_Ȯ��_����ü
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

#pragma region ���� �Լ�
public:
	// ���� ���� �Լ�
	void Run();

	// Ű Ȯ�� �Լ�
	bool GetKey(int keyCode);
	bool GetKeyDown(int keyCode);
	bool GetKeyUp(int keyCode);

	// ���� ���� �Լ�
	void Quit();

	void AddLevel(Level* newLevel);

#pragma endregion

#pragma region ���� �Լ�
private:
	void ProcessInput();

	void BeginPlay();
	void Tick(float deltaTime = 0.0f);
	void Render();
#pragma endregion

#pragma region �ɹ� ����
private:
	bool isQuit = false;
	KeyState _keyStates[256];
	Level* _mainLevel = nullptr;
#pragma endregion
};

#endif
