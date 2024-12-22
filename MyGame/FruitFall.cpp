#include "FruitFall.h"

ow::Unit Fruit::addFruit()
{
	int x = rand() % 800;
	ow::Unit fruit{ "../Power/PowerAssets/Images/apple_2.png", x, ow::PowerWindow::GetWindow()->getHeight() - 50};
	return fruit;
}

void Fruit::deleteFruit(ow::Unit& fruit)
{
	fruit.setVisibility(false);
}

void Fruit::fallingFruit(ow::Unit& fruit) {
	fruit.updateYCoord(-5);
	if (fruit.getYCoord() < 50) {
		deleteFruit(fruit);
	}
}

