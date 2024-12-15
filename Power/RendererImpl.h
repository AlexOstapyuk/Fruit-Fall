#pragma once

#include "Shaders.h"
#include "Image.h"

namespace ow {
	class RendererImpl {
	
	public:
		virtual void Draw(Image& file, int xCoord, int yCoord) = 0;
		virtual void Draw(Image& file, int xCoord, int yCoord, Shaders& shader) = 0;


		virtual void ClearScreen() = 0;

		virtual ~RendererImpl() {};
	};
}
