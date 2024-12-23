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
		
		if (face_original == true) {
			ow::Renderer::Draw(character);
		}
		else {
			ow::Renderer::DrawOpposite(character);
		}
		

		Fruit fruit;

		clock_t currentTime = clock();
		double elapsedSeconds = double(currentTime - lastFruit) / CLOCKS_PER_SEC;

		if (elapsedSeconds > 2.0) {
			storage.push_back(fruit.addFruit());
			lastFruit = currentTime;

		}
		

		for (ow::Unit& image : storage) {
			ow::Renderer::Draw(image);
			
			fruit.fallingFruit(image);
			fruit.collideFruit(image, character);
		}

	} 
private:
	ow::Unit character{ "../Power/PowerAssets/Images/pacman.png", 100, 50 };
	ow::Unit background{ "../Power/PowerAssets/Images/nature_background.png", 0, 0 };
	//ow::Unit fruit{ "../Power/PowerAssets/Images/apple_2.png" };
	bool face_original = true;
	std::vector<ow::Unit> storage;
	clock_t lastFruit;



	void MyKeyHandler(const ow::KeyEvent& event) {
		if (event.getKeyAction() == ow::KeyEvent::KeyAction::Press) {
			switch (event.getKeyCode()) 
			{
			case POW_KEY_LEFT:
				face_original = true;
				character.updateXCoord(-10);
				break;
			case POW_KEY_RIGHT:
				face_original = false;
				character.updateXCoord(10);
				break;
			}
		}
		if (event.getKeyAction() == ow::KeyEvent::KeyAction::Repeat) {
			switch (event.getKeyCode())
			{
			case POW_KEY_LEFT:
				face_original = true;
				character.updateXCoord(-10);
				break;
			case POW_KEY_RIGHT:
				face_original = false;
				character.updateXCoord(10);
				break;
			}
		}
	}
};

POWER_START(GameApp);