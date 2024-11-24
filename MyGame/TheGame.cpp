#include "Power.h"
#include <iostream>

class GameApp : public ow::PowerApp
{
	virtual void Initialize() override
	{
		std::cout << "Starting Game..." << std::endl;
	}

	virtual void Update() override
	{
		//std::cout << "Reloading..." << std::endl;
	}
};

POWER_START(GameApp);