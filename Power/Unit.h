#pragma once

#include "PowerUtil.h"
#include "Image.h"
#include "pch.h"

namespace ow {
	class POW_API Unit {
	public:
		Unit(const std::string& fileName, int xCoord, int yCoord, bool visible);

	private:
		Image mImage;
		int mXCoord{ 0 };
		int mYCoord{ 0 };
		bool mIsVisible{ true };
	};
}
