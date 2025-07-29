#ifndef __ENGINE_H__
#define __ENGINE_H__

#include "Core.h"
#include "Input.h"
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
	
#pragma region Ŭ���� ���� static �Լ�
public:
	static Engine& GetInstance();
#pragma endregion

#pragma region ���� �Լ�
public:
	// ���� ���� �Լ�
	void Run();

	

	// ���� ���� �Լ�
	void CleanUp();
	void Quit();

	void AddLevel(Level* newLevel);

#pragma endregion

#pragma region ���� �Լ�
private:
	void BeginPlay();
	void Tick(float deltaTime = 0.0f);
	void Render();
#pragma endregion

#pragma region static ����
private:
	static Engine* _static_instance;
#pragma endregion

#pragma region �ɹ� ����
private:
	bool isQuit = false;
	Level* _mainLevel = nullptr;
	Input _input;
#pragma endregion
};

#endif
