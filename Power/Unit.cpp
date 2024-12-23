#include "pch.h"
#include "Unit.h"

namespace ow {
	Unit::Unit(const std::string& fileName, int xCoord, int yCoord, bool visible):
		mImage(fileName), mXCoord(xCoord), mYCoord(yCoord), mIsVisible(visible)
	{
	}

	int Unit::getWidth() const
	{
		return mImage.getWidth();
	}

	int Unit::getHeight() const
	{
		return mImage.getHeight();
	}

	int Unit::getXCoord() const
	{
		return mXCoord;
	}

	int Unit::getYCoord() const
	{
		return mYCoord;
	}

	void Unit::setCoords(int x, int y)
	{
		mXCoord = x;
		mYCoord = y;
	}

	void Unit::updateXCoord(int amount)
	{
		mXCoord += amount;
	}

	void Unit::updateYCoord(int amount)
	{
		mYCoord += amount;
	}

	/*void Unit::deleteImage()
	{
		mImage.deleteImage();
	}*/

	bool Unit::isVisible() const
	{
		return mIsVisible;
	}

	void Unit::setVisibility(bool visibility)
	{
		mIsVisible = visibility;
	}
	bool UnitsOverlap(const Unit& a, const Unit& b)
	{
		int left_a{ a.mXCoord };
		int right_a{ a.mXCoord + a.mImage.getWidth() };
		int left_b{ b.mXCoord };
		int right_b{ b.mXCoord + b.mImage.getWidth() };

		bool x_intersection{ (left_a <= left_b && left_b <= right_a) || 
			left_b <= left_a && left_a <= right_b};

		int bot_a{ a.mYCoord };
		int top_a{ a.mYCoord + a.mImage.getHeight()};
		int bot_b{ b.mYCoord };
		int top_b{ b.mYCoord + b.mImage.getHeight() };

		bool y_intersection{ (bot_a <= bot_b && bot_b <= top_a) || 
			bot_b <= bot_a && bot_a <= top_b};

		return x_intersection && y_intersection;

	}
}
