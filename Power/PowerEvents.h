#pragma once

#include "PowerApp.h"


namespace ow {
	class POW_API KeyEvent {
	public:
		//set values to key usage
		enum KeyAction { Press, Release, Repeat };

		KeyEvent(int keyCode, KeyAction action = KeyAction::Press);

		int getKeyCode() const;
		KeyAction getKeyAction() const;

		

	private:
		int mKeyCode{ -1 };
		KeyAction mAction{ KeyAction::Press };
	};

	class POW_API WindowEvent {
	public:
		enum class WindowAction{Close, Minimize, Maximize, Resize};

		WindowEvent(WindowAction action);

		WindowAction GetWindowAction() const;

	private:
		WindowAction mAction{ WindowAction::Resize };
	};
}