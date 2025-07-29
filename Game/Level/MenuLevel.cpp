#include "MenuLevel.h"
#include "Input.h"

#include "Game/Game.h"

#include "UTils/Utils.h"

#include <iostream>

MenuLevel::MenuLevel()
{
	_items.emplace_back(new MenuItem(
		"Resume Game",
		[]() {
			/* 메뉴 토글 기능 추가*/
			Game::GetInstance().ToggleMenu();
		}
	));
	_items.emplace_back(new MenuItem(
		"Quit Game",
		[]() {
			Game::GetInstance().Quit();
		}
	));

	// 아이템 수 미리 저장
	_menuItemLength = static_cast<int>(_items.size());	// size_t -> int
}

MenuLevel::~MenuLevel()
{
	for (MenuItem* pItem : _items)
	{
		SafeDelete(pItem);
	}
	_items.clear();
}

void MenuLevel::Tick(float deltaTime)
{
	super::Tick(deltaTime);

	// 입력 처리
	if (Input::GetInstance().GetKeyDown(VK_UP))
	{
		_currentIndex = (_currentIndex - 1 + _menuItemLength) % _menuItemLength;
	}
	if (Input::GetInstance().GetKeyDown(VK_DOWN))
	{
		_currentIndex = (_currentIndex + 1) % _menuItemLength;
	}
	if (Input::GetInstance().GetKeyDown(VK_RETURN))
	{
		_items[_currentIndex]->_fOnSelected();
	}
	if (Input::GetInstance().GetKeyDown(VK_ESCAPE))
	{
		Game::GetInstance().ToggleMenu();

		_currentIndex = 0;
	}

}

void MenuLevel::Render()
{
	super::Render();

	// 색상 & 좌표 정리.
	Utils::SetConsolePosition(COORD{ 0, 0 });
	Utils::SetConsoleTextColor(static_cast<WORD>(_unSelectedColor));


	std::cout << "SokobanGame\n\n";

	// 메뉴 아이템 렌더링
	for (int idx = 0; idx < _menuItemLength; ++idx)
	{
		// 아이템 색상 확인.
		Color textColor = (idx == _currentIndex) ? _selectedColor : _unSelectedColor;
		
		// 색깔 선택
		Utils::SetConsoleTextColor(static_cast<WORD>(textColor));
		
		// 메뉴 아이템 출력
		std::cout << _items[idx]->_menuText << "\n";
	}
}
