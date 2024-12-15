#include "pch.h"

#include "PowerApp.h"
#include "PowerWindow.h"
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
		ow::PowerWindow::GetWindow()->CreateWindow(800, 600, "test");

		Renderer::Init();

		Initialize();

		

		//Shader Code

		ow::Shaders shaders{ 
			"../Power/PowerAssets/Shaders/defaultVertexShader.glsl", 
			"../Power/PowerAssets/Shaders/defaultFragmentShader.glsl"};

		shaders.setIntUniform("ScreenDim", { 800,600 });


		//Texture
		ow::Image pic{ "../Power/PowerAssets/Images/thorfinn.png" };





		while (ShouldContinue) {
			Update();

			Renderer::ClearScreen();

			Renderer::Draw(pic, 100, 100);

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


}

