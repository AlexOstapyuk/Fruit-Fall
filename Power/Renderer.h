#pragma once

#include "pch.h"
#include "PowerUtil.h"
#include "Image.h"
#include "Unit.h"
#include "Shaders.h"
#include "RendererImpl.h"

namespace ow {
	class POW_API Renderer
	{
	public:
		static void Init();

		static void Draw(Image& file, int xCoord, int yCoord);
		static void Draw(Image& file, int xCoord, int yCoord, Shaders& shader);
		static void Draw(Unit& unit);
		static void Draw(Unit& unit, Shaders& shaders);
		
		static void DrawOpposite(Image& file, int xCoord, int yCoord);
		static void DrawOpposite(Unit& unit);
		static void DrawOpposite(Image& file, int xCoord, int yCoord, Shaders& shader);
		static void DrawOpposite(Unit& unit, Shaders& shaders);


		static void ClearScreen();

	private:
		Renderer();
		std::unique_ptr<RendererImpl> mImplementation;
		inline static std::unique_ptr<Renderer> mInstance;
	};
}