#pragma once

#include "Power.h"

class POW_API Fruit {
public:
	ow::Unit addFruit();
	void deleteFruit(ow::Unit& fruit);

	void fallingFruit(ow::Unit& fruit);
private:

};