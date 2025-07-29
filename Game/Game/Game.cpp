#include "Game.h"

#include "Level/SokobanLevel.h"
#include "Level/MenuLevel.h"

/*
*		static ���� �ʱ�ȭ
*/

Game* Game:: _static_instance = nullptr;

/*
*		Ư�� ��� �Լ�
*/

Game::Game()
{
	_static_instance = this;

	AddLevel(new SokobanLevel());

	_menuLevel = new MenuLevel();
}

Game::~Game()
{
	if (_showMenu == true)
	{ 
		SafeDelete(_backLevel);
		_mainLevel = nullptr;
	}
	else
	{ 
		SafeDelete(_menuLevel);
	}
	CleanUp();


	Engine::CleanUp();
}

void Game::ToggleMenu()
{
	// ȭ�� ����
	system("cls");

	_showMenu = !_showMenu;
	if (_showMenu) {
		// ���� ������ �ڷ� �б�.
		_backLevel = _mainLevel;
		
		// �޴� ������ ���� ������ ����
		_mainLevel = _menuLevel;
	}
	else
	{
		// ���� ������ ���� ������ ����
		_mainLevel = _backLevel;
	}
}

void Game::CleanUp()
{

}

Game& Game::GetInstance()
{
	return *_static_instance;
}
