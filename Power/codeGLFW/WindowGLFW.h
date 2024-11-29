#pragma once

#include "../WindowImpl.h"
#include "GLFW/glfw3.h"

namespace ow {
	class WindowGLFW : public WindowImpl {
	public:
		WindowGLFW();

		virtual void Create(int width, int height, std::string windowName) override;
		virtual int getWidth() const override;
		virtual int getHeight() const override;

	private:
		GLFWwindow* windowPtr{ nullptr };
	};
}