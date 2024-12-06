#include "pch.h"

#include "WindowGLFW.h"
#include "PowerUtil.h"


namespace ow {
	WindowGLFW::WindowGLFW()
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}

	void WindowGLFW::Create(int width, int height, std::string windowName)
	{
		mWindowPtr = glfwCreateWindow(800, 600, windowName.c_str(), NULL, NULL);

		if (!mWindowPtr) {
			POW_ERROR("Failed to create GLFW!!!");
		}

		glfwMakeContextCurrent(mWindowPtr);
	}
	int WindowGLFW::getWidth() const
	{
		int width{ 0 };
		int height{ 0 };

		glfwGetWindowSize(mWindowPtr, &width, &height);


		return width;
	}
	int WindowGLFW::getHeight() const
	{
		int width{ 0 };
		int height{ 0 };

		glfwGetWindowSize(mWindowPtr, &width, &height);

		return height;
	}
	void WindowGLFW::SwapBuffers()
	{
		glfwSwapBuffers(mWindowPtr);
	}
	void WindowGLFW::PollEvents()
	{
		glfwPollEvents();
	}
}