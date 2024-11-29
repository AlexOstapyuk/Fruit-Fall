#include "Power.h"
#include <iostream>

class GameApp : public ow::PowerApp
{
	virtual void Initialize() override
	{
		POW_LOG("Starting Game...");

		ow::PowerWindow win;
		win.CreateWindow(800, 600, "test");
	}

	virtual void Update() override
	{
		//std::cout << "Reloading..." << std::endl;
	} 
};

POWER_START(GameApp);