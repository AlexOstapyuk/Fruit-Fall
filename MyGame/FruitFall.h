#pragma once

#include "Power.h"
#include "Counter.h"

class POW_API Fruit {
public:
	ow::Unit addFruit();
	void deleteFruit(ow::Unit& fruit);

	bool collideFruit(ow::Unit& fruit, ow::Unit& character);
	void fallingFruit(ow::Unit& fruit);
	
private:
	
};