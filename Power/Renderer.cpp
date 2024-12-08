#include "pch.h"

#include "Renderer.h"

namespace ow {
	Renderer::Renderer()
	{

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

	void Renderer::Draw(Image& file, int xCoord, int yCoord, Shaders shaders)
	{
		mInstance->mImplementation->Draw(file, xCoord, yCoord, shaders);
	}
}