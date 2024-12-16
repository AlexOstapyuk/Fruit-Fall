#pragma once

#include "pch.h"
#include "PowerUtil.h"
#include "PowerEvents.h"

constexpr int FPS_RATE{ 60 };

namespace ow 
{
	class POW_API PowerApp
	{
	public:
		void Run();
		virtual void Initialize();
		virtual void Update();
		virtual void Shutdown();

		void setKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler);
		void setWindowEventHandler(std::function<void(const WindowEvent&)> newHandler);


	private:
		bool mShouldContinue{ true };

		std::chrono::steady_clock::time_point mNextFrameTime;
		std::chrono::milliseconds mFrameDuration{ std::chrono::milliseconds{1000} / FPS_RATE };
		float num = 1 / 60;
	};
}