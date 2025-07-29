#ifndef __GAME_H__
#define __GAME_H__

#include "Engine.h"

class Game : public Engine
{
public:
	Game();
	~Game();

public:
	void ToggleMenu();
	
	virtual void CleanUp() override;

public:
	static Game& GetInstance();

private:
	static Game* _static_instance;

	Level* _menuLevel = nullptr;
	Level* _backLevel = nullptr;
	bool _showMenu = false;
};

#endif
