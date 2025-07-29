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

	// �޴� Text
	char* _menuText = nullptr;

	// �޴� ���� �� ������ ����
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

	// �޴� ������ ��
	int _menuItemLength = 0;
};