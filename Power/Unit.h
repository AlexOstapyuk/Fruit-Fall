#pragma once

#include "PowerUtil.h"
#include "Image.h"
#include "pch.h"

namespace ow {
	class POW_API Unit {
	public:
		Unit(const std::string& fileName, int xCoord, int yCoord, bool visible=true);

		int getWidth() const;
		int getHeight() const;

		int getXCoord() const;
		int getYCoord() const;
		void setCoords(int x, int y);
		void updateXCoord(int amount);
		void updateYCoord(int amount);

		/*void deleteImage();*/

		bool isVisible() const;
		void setVisibility(bool visibility);

	private:
		Image mImage;
		int mXCoord{ 0 };
		int mYCoord{ 0 };
		bool mIsVisible{ true };

		friend bool POW_API UnitsOverlap(const Unit& a, const Unit& b);
		friend class Renderer;
	};
	bool POW_API UnitsOverlap(const Unit& a, const Unit& b);
}
