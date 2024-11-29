#pragma once

#include "pch.h"
#include "WindowImpl.h"
#include "PowerUtil.h"

namespace ow {
	class POW_API PowerWindow {
	public:
		PowerWindow();

		void CreateWindow(int width, int height, std::string windowName);

		int getWidth() const;
		int getHeight() const;

	private:
		WindowImpl* implementation{ nullptr };
	};
}
