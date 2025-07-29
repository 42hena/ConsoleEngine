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
			/* �޴� ��� ��� �߰�*/
			Game::GetInstance().ToggleMenu();
		}
	));
	_items.emplace_back(new MenuItem(
		"Quit Game",
		[]() {
			Game::GetInstance().Quit();
		}
	));

	// ������ �� �̸� ����
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

	// �Է� ó��
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

	// ���� & ��ǥ ����.
	Utils::SetConsolePosition(COORD{ 0, 0 });
	Utils::SetConsoleTextColor(static_cast<WORD>(_unSelectedColor));


	std::cout << "SokobanGame\n\n";

	// �޴� ������ ������
	for (int idx = 0; idx < _menuItemLength; ++idx)
	{
		// ������ ���� Ȯ��.
		Color textColor = (idx == _currentIndex) ? _selectedColor : _unSelectedColor;
		
		// ���� ����
		Utils::SetConsoleTextColor(static_cast<WORD>(textColor));
		
		// �޴� ������ ���
		std::cout << _items[idx]->_menuText << "\n";
	}
}
