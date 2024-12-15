#include "pch.h"

#include "Renderer.h"

namespace ow {
	Renderer::Renderer()
	{
#ifdef POW_OPENGL_STBI
		mImplementation = std::unique_ptr<RendererImpl>{ new OpenGLRenderer() };
#else
		#only_opengl_is_supported_so_far
#endif
	}

	void Renderer::Init()
	{
		if (mInstance == nullptr) {
			mInstance = std::unique_ptr<Renderer>(new Renderer);
		}
	}

	void Renderer::Draw(Image& file, int xCoord, int yCoord)
	{
		mInstance->mImplementation->Draw(file, xCoord, yCoord);
	}

	void Renderer::Draw(Image& file, int xCoord, int yCoord, Shaders shader)
	{
		mInstance->mImplementation->Draw(file, xCoord, yCoord, shader);
	}
	void Renderer::ClearScreen()
	{
		mInstance->mImplementation->ClearScreen();
	}
}