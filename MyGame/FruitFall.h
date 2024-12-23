#pragma once

#include "Power.h"

class POW_API Fruit {
public:
	ow::Unit addFruit();
	void deleteFruit(ow::Unit& fruit);

	void collideFruit(ow::Unit& fruit, ow::Unit& character);
	void fallingFruit(ow::Unit& fruit);
	
private:

};