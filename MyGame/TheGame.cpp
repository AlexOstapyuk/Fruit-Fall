#include "Power.h"
#include "FruitFall.h"
#include "Counter.h"
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
		
		//These statements to make sure the character is facing the same way as the direction it is going
		if (face_left == true) {
			ow::Renderer::Draw(character);
		}
		else {
			ow::Renderer::DrawOpposite(character);
		}
		
		//Print the current counter, default before collision is 1
		count.printCounter();
		
		//Keep track of the time
		clock_t currentTime = clock();
		double elapsedSeconds = double(currentTime - lastFruit) / CLOCKS_PER_SEC;

		//Make sure at least 2 seconds have past before adding another fruit
		if (elapsedSeconds > 2.0) {
			storage.push_back(fruit.addFruit());
			lastFruit = currentTime;

		}
		
		//loop to traverse through all the current fruits
		for (ow::Unit& image : storage) {
			ow::Renderer::Draw(image);
			
			fruit.fallingFruit(image);
			//if the image is currently visible and it collides with an image, add to the counter
			if (image.isVisible() && fruit.collideFruit(image, character)) {
				count.addCounter();
				collide = true;

			}
			
			
		}
		//reset collide
		if (collide == true) {
			collide = false;
		}
		

	} 
private:
	ow::Unit character{ "../MyGame/Assets/bug_basket.png", 100, 50 };
	ow::Unit background{ "../MyGame/Assets/pixil-frame.png", 0, 0 };
	Fruit fruit;
	Counter count;
	bool face_left{ false }; //image is originally NOT facing left
	bool collide{ false };
	std::vector<ow::Unit> storage;
	clock_t lastFruit;



	void MyKeyHandler(const ow::KeyEvent& event) {
		if (event.getKeyAction() == ow::KeyEvent::KeyAction::Press) {
			switch (event.getKeyCode()) 
			{
			case POW_KEY_LEFT:
				face_left = false;
				if (character.getXCoord() > 0) {
					character.updateXCoord(-10);
				}
				break;
			case POW_KEY_RIGHT:
				face_left = true;
				if (character.getXCoord() < ow::PowerWindow::GetWindow()->getWidth() - character.getWidth()) {
					character.updateXCoord(10);
				}
				break;
			}
		}
		if (event.getKeyAction() == ow::KeyEvent::KeyAction::Repeat) {
			switch (event.getKeyCode())
			{
			case POW_KEY_LEFT:
				face_left = false;
				if (character.getXCoord() > 0) {
					character.updateXCoord(-10);
				}
				break;
			case POW_KEY_RIGHT:
				face_left = true;
				if (character.getXCoord() < ow::PowerWindow::GetWindow()->getWidth() - character.getWidth()) {
					character.updateXCoord(10);
				}
				break;
			}
		}
	}
};

POWER_START(GameApp);