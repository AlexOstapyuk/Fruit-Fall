#include "Power.h"
#include <iostream>

class GameApp : public ow::PowerApp
{
	virtual void Initialize() override
	{
		POW_LOG("Starting Game...");

		setKeyEventHandler([this](const ow::KeyEvent& event) {MyKeyHandler(event);});
	}

	virtual void Update() override
	{
		ow::Renderer::Draw(character);
	} 
private:
	ow::Unit character{ "../Power/PowerAssets/Images/thorfinn.png", 100, 100 };

	void MyKeyHandler(const ow::KeyEvent& event) {
		if (event.getKeyAction() == ow::KeyEvent::KeyAction::Press) {
			switch (event.getKeyCode()) 
			{
			case POW_KEY_LEFT:
				character.updateXCoord(-10);
				break;
			case POW_KEY_RIGHT:
				character.updateXCoord(10);
				break;
			}
		}
	}
};

POWER_START(GameApp);