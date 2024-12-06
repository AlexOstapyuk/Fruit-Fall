#include "pch.h"

#include "PowerWindow.h"
#include "codeGLFW/WindowGLFW.h"

namespace ow {
	PowerWindow::PowerWindow()
	{
		//create implemenatation object and point "implementation" pointer to it
#ifdef POW_GLFW
		implementation = std::unique_ptr<WindowImpl>{ new WindowGLFW };
#else
		#window_implementation_isnt_chosen
#endif
	}
	
	
	void PowerWindow::Init()
	{
		if (inst == nullptr) {
			inst = std::unique_ptr<PowerWindow>{ new PowerWindow };
		}
	}

	std::unique_ptr<PowerWindow>& PowerWindow::GetWindow()
	{
		return inst;
	}

	void PowerWindow::CreateWindow(int width, int height, std::string windowName)
	{
		implementation->Create(width, height, windowName);
	}
	
	
	int PowerWindow::getWidth() const
	{
		return implementation->getWidth();
	}
	
	
	int PowerWindow::getHeight() const
	{
		return implementation->getHeight();
	}

	void PowerWindow::SwapBuffers()
	{
		implementation->SwapBuffers();
	}

	void PowerWindow::PollEvents()
	{
		implementation->PollEvents();
	}
}