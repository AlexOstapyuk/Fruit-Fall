#pragma once

#define POWER_START(ClassName) \
int main()\
{\
	ClassName game ;\
	game.Run();\
	return 0;\
}