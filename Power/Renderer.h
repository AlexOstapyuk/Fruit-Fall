#pragma once

#include "pch.h"
#include "PowerUtil.h"
#include "Image.h"
#include "Shaders.h"

namespace ow {
	class POW_API Renderer
	{
	public:
		Renderer();

		static void Draw(Image& file, int xCoord, int yCoord);
		static void Draw(Image& file, int xCoord, int yCoord, Shaders shaders);

	private:
		std::unique_ptr<RendererImpl> mImplementation;
		inline static std::unique_ptr<Renderer> mInstance;
	};
}