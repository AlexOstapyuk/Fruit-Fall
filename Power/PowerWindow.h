#pragma once

#include "pch.h"
#include "WindowImpl.h"
#include "PowerUtil.h"
#include "PowerEvents.h"

namespace ow {
	class POW_API PowerWindow {
	public:
		static void Init();
		static std::unique_ptr<PowerWindow>& GetWindow();

		void CreateWindow(int width, int height, std::string windowName);

		int getWidth() const;
		int getHeight() const;

		void setKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler);
		void setWindowEventHandler(std::function<void(const WindowEvent&)> newHandler);

		void SwapBuffers();
		void PollEvents();

	private:
		std::unique_ptr<WindowImpl> implementation{ nullptr };

		PowerWindow();

		inline static std::unique_ptr<PowerWindow> inst;
	};
}
