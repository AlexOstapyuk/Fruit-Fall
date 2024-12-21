#pragma once

#include "../WindowImpl.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "pch.h"
#include "PowerEvents.h"

namespace ow {
	class WindowGLFW : public WindowImpl {
	public:
		WindowGLFW();

		virtual void Create(int width, int height, std::string windowName) override;
		virtual int getWidth() const override;
		virtual int getHeight() const override;

		virtual void setKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler) override;
		virtual void setWindowEventHandler(std::function<void(const WindowEvent&)> newHandler) override;

		virtual void SwapBuffers() override;
		virtual void PollEvents() override;

	private:
		GLFWwindow* mWindowPtr{ nullptr };


		struct Callbacks {
			std::function<void(const KeyEvent&)> KeyEventHandler{ [](const KeyEvent&) {} };
			std::function<void(const WindowEvent&)> WindowEventHandler{ [](const WindowEvent&) {} };
		} mCallbacks;
	};
}