#include "FruitFall.h"

ow::Unit Fruit::addFruit()
{
	int x = rand() % ow::PowerWindow::GetWindow()->getWidth()-20;
	ow::Unit fruit{ "../Power/PowerAssets/Images/apple_2.png", x, ow::PowerWindow::GetWindow()->getHeight() - 50};
	return fruit;
}

void Fruit::deleteFruit(ow::Unit& fruit)
{
	fruit.setVisibility(false);
}

void Fruit::collideFruit(ow::Unit& fruit, ow::Unit& character)
{
	if (ow::UnitsOverlap(fruit, character) == true) {
		deleteFruit(fruit);
	}
}

void Fruit::fallingFruit(ow::Unit& fruit) {
	fruit.updateYCoord(-5);
	if (fruit.getYCoord() < 10) {
		deleteFruit(fruit);
	}
}
