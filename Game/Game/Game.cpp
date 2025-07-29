#include "Game.h"

#include "Level/SokobanLevel.h"
#include "Level/MenuLevel.h"

/*
*		static 변수 초기화
*/

Game* Game:: _static_instance = nullptr;

/*
*		특수 멤버 함수
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
	// 화면 정리
	system("cls");

	_showMenu = !_showMenu;
	if (_showMenu) {
		// 게임 레벨을 뒤로 밀기.
		_backLevel = _mainLevel;
		
		// 메뉴 레벨을 메인 레벨로 설정
		_mainLevel = _menuLevel;
	}
	else
	{
		// 게임 레벨을 메인 레벨로 설정
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
