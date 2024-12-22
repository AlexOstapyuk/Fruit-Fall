#include "Power.h"
#include "FruitFall.h"
#include <iostream>
#include <vector>
#include <ctime>

class GameApp : public ow::PowerApp
{
	virtual void Initialize() override
	{
		POW_LOG("Starting Game...");

		setKeyEventHandler([this](const ow::KeyEvent& event) {MyKeyHandler(event);});
	}

	virtual void Update() override
	{
		ow::Renderer::Draw(background);
		ow::Renderer::Draw(character);

		Fruit fruit;

		clock_t currentTime = clock();
		double elapsedSeconds = double(currentTime - lastFruit) / CLOCKS_PER_SEC;

		if (elapsedSeconds > 2.0) {
			moreFruit();
			lastFruit = currentTime;
		}
		

		/*for (ow::Unit& fruit : storage) {
			ow::Renderer::Draw(fruit);
		}*/
		for (ow::Unit& image : storage) {
			ow::Renderer::Draw(image);
			fruit.fallingFruit(image);
		}
	} 
private:
	ow::Unit character{ "../Power/PowerAssets/Images/thorfinn.png", 100, 50 };
	ow::Unit background{ "../Power/PowerAssets/Images/nature_background.png", 0, 0 };
	//ow::Unit fruit{ "../Power/PowerAssets/Images/apple_2.png" };
	//bool face_left = true;
	std::vector<ow::Unit> storage;
	clock_t lastFruit;



	void MyKeyHandler(const ow::KeyEvent& event) {
		if (event.getKeyAction() == ow::KeyEvent::KeyAction::Press) {
			switch (event.getKeyCode()) 
			{
			case POW_KEY_LEFT:
				/*if (face_left == false) {

				}*/
				character.updateXCoord(-10);
				break;
			case POW_KEY_RIGHT:
				character.updateXCoord(10);
				break;
			case POW_KEY_SPACE:
				character.updateYCoord(100);
				break;
			}
		}
		if (event.getKeyAction() == ow::KeyEvent::KeyAction::Release) {
			switch (event.getKeyCode()) {
			case POW_KEY_SPACE:
				character.updateYCoord(-100);
				break;
			}
		}
		if (event.getKeyAction() == ow::KeyEvent::KeyAction::Repeat) {
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

	void moreFruit() {
		Fruit fruit;
		storage.push_back(fruit.addFruit());
		/*for (ow::Unit& image : storage) {
			fruit.fallingFruit(image);
		}*/
	}
};

POWER_START(GameApp);