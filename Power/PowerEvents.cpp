#include "pch.h"
#include "PowerEvents.h"

namespace ow {
	KeyEvent::KeyEvent(int keyCode, KeyAction action): mKeyCode(keyCode), mAction(action)
	{
	}

	int KeyEvent::getKeyCode() const
	{
		return mKeyCode;
	}

	KeyEvent::KeyAction KeyEvent::getKeyAction() const
	{
		return mAction;
	}



	WindowEvent::WindowEvent(WindowAction action): mAction(action)
	{
	}
	
	WindowEvent::WindowAction WindowEvent::GetWindowAction() const
	{
		return mAction;
	}
}
