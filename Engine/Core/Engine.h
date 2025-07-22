#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "Core.h"
#include <Windows.h>

class ENGINE_API Engine
{
#pragma region Ư�� �ɹ� �Լ�
public:
	Engine()							= default;
	~Engine()							= default;

public:
	Engine(const Engine&)				= delete;
	Engine& operator=(const Engine&)	= delete;
	Engine(Engine&&)					= delete;
	Engine& operator=(Engine&&)			= delete;
#pragma endregion

#pragma region ���� �Լ�
public:
	// ���� ���� �Լ�
	void Run();

	// ���� ���� �Լ�
	void Quit();
#pragma endregion

#pragma region ���� �Լ�
private:
	void ProcessInput();
	void Update(float deltaTime = 0.0f);
	void Render();
#pragma endregion

#pragma region �ɹ� ����
private:
	bool isQuit = false;
#pragma endregion
};

#endif
