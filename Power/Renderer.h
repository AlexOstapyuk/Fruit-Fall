#pragma once

#include "pch.h"
#include "PowerUtil.h"
#include "Image.h"
#include "Shaders.h"

namespace ow {
	class POW_API Renderer
	{
	public:
		static void Init();

		static void Draw(Image& file, int xCoord, int yCoord);
		static void Draw(Image& file, int xCoord, int yCoord, Shaders shader);

		static void ClearScreen();

	private:
		Renderer();
		std::unique_ptr<RendererImpl> mImplementation;
		inline static std::unique_ptr<Renderer> mInstance;
	};
}