#pragma once

#include "Power.h"
#include "FruitFall.h"
#include <vector>
#include <iostream>

class Counter {
public:
	void printCounter();
	void addCounter();

	std::string zero_img{ "../Power/PowerAssets/Images/0.png" };
	std::string one_img{ "../Power/PowerAssets/Images/1.png" };
	std::string two_img{ "../Power/PowerAssets/Images/2.png" };
	std::string three_img{ "../Power/PowerAssets/Images/3.png" };
	std::string four_img{ "../Power/PowerAssets/Images/4.png" };
	std::string five_img{ "../Power/PowerAssets/Images/5.png" };
	std::string six_img{ "../Power/PowerAssets/Images/6.png" };
	std::string seven_img{ "../Power/PowerAssets/Images/7.png" };
	std::string eight_img{ "../Power/PowerAssets/Images/8.png" };
	std::string nine_img{ "../Power/PowerAssets/Images/9.png" };
private:
	std::vector<int> nums{ {0} };

	
};