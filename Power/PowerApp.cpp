#include "pch.h"

#include "PowerApp.h"
#include "PowerWindow.h"
#include "PowerEvents.h"
#include "Image.h"
#include "Shaders.h"
#include "Renderer.h"

#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/glad.h"

#include "stb_image.h"

namespace ow
{
	void PowerApp::Run()
	{
		ow::PowerWindow::Init();
		ow::PowerWindow::GetWindow()->CreateWindow(1000, 800, "test");

		Renderer::Init();

		setWindowEventHandler(
			[this](const WindowEvent& event) {DefaultWindowEventHandler(event); });

		Initialize();



		//Texture
		ow::Image pic{ "../Power/PowerAssets/Images/thorfinn.png" };
		int x{ 100 };


		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;


		while (mShouldContinue) {
			Update();

			Renderer::ClearScreen();

			Renderer::Draw(pic, x, 100);
			x += 2;

			std::this_thread::sleep_until(mNextFrameTime);
			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

			ow::PowerWindow::GetWindow()->SwapBuffers();
			ow::PowerWindow::GetWindow()->PollEvents();
		}

		Shutdown();
	}

	void PowerApp::Initialize()
	{
	}

	void PowerApp::Update()
	{
	}

	void PowerApp::Shutdown()
	{
	}


	void PowerApp::setKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler)
	{
		ow::PowerWindow::GetWindow()->setKeyEventHandler(newHandler);
	}

	void PowerApp::setWindowEventHandler(std::function<void(const WindowEvent&)> newHandler)
	{
		ow::PowerWindow::GetWindow()->setWindowEventHandler(newHandler);
	}

	void PowerApp::DefaultWindowEventHandler(const WindowEvent& event)
	{
		if (event.GetWindowAction() == WindowEvent::WindowAction::Close) {
			mShouldContinue = false;
		}
		
	}



}

