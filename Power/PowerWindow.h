#pragma once

#include "pch.h"
#include "WindowImpl.h"
#include "PowerUtil.h"

namespace ow {
	class POW_API PowerWindow {
	public:
		static void Init();
		static std::unique_ptr<PowerWindow>& GetWindow();

		void CreateWindow(int width, int height, std::string windowName);

		int getWidth() const;
		int getHeight() const;

		void SwapBuffers();
		void PollEvents();

	private:
		std::unique_ptr<WindowImpl> implementation{ nullptr };

		PowerWindow();

		inline static std::unique_ptr<PowerWindow> inst;
	};
}
