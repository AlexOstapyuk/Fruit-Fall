#include "Power.h"
#include <iostream>

class GameApp : public ow::PowerApp
{
	virtual void Initialize() override
	{
		POW_LOG("Starting Game...");

		
	}

	virtual void Update() override
	{
		//std::cout << "Reloading..." << std::endl;
	} 
};

POWER_START(GameApp);