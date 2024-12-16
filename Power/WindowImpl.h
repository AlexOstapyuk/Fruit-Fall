#pragma once

#include "pch.h"
#include "PowerEvents.h"

namespace ow {
	class WindowImpl {
	public:
		virtual void Create(int width, int height, std::string windowName) = 0;
		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;
		virtual void setKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler) = 0;
		virtual void setWindowEventHandler(std::function<void(const WindowEvent&)> newHandler) = 0;
		virtual void SwapBuffers() = 0;
		virtual void PollEvents() = 0;
	};
}