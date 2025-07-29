#pragma once

#include "Level/Level.h"

#include "Actor/Actor.h"

#include <vector>

struct MenuItem
{
	using OnSelected = void(*)();
	
	MenuItem(const char* text, OnSelected onSelected)
		: _fOnSelected(onSelected)
	{
		size_t length = strlen(text) + 1;
		_menuText = new char[length];
		strcpy_s(_menuText, length, text);
	}

	~MenuItem()
	{
		SafeDeleteArray(_menuText);
	}

	// 메뉴 Text
	char* _menuText = nullptr;

	// 메뉴 선택 시 실행할 동작
	OnSelected _fOnSelected = nullptr;
};

class MenuLevel : public Level
{
	RTTI_DECLARATIONS(MenuLevel, Level)

public:
	MenuLevel();
	~MenuLevel();

public:
	virtual void Tick(float deltaTime) override;
	virtual void Render() override;


private:

	int _currentIndex = 0;
	
	Color _selectedColor = Color::Color_Green;
	Color _unSelectedColor = Color::Color_White;

	std::vector<MenuItem*> _items;

	// 메뉴 아이템 수
	int _menuItemLength = 0;
};