#include "pch.h"

#include "PowerWindow.h"
#include "codeGLFW/WindowGLFW.h"

namespace ow {
	PowerWindow::PowerWindow()
	{
		//create implemenatation object and point "implementation" pointer to it
#ifdef POW_GLFW
		implementation = new WindowGLFW;
#else
		#window_implementation_isnt_chosen
#endif
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
}