#pragma once

#include "../RendererImpl.h"
#include "Shaders.h"

namespace ow {
	class OpenGLRenderer : public RendererImpl {
	public:
		OpenGLRenderer();

		virtual void Draw(Image& file, int xCoord, int yCoord) override;
		virtual void Draw(Image& file, int xCoord, int yCoord, Shaders& shader) override;


		virtual void ClearScreen() override;
	private:
		unsigned int mVBO{ 0 };
		unsigned int mVAO{ 0 };
		unsigned int mEBO{ 0 };

		Shaders mDefaultShaders{
			"../PowerAssets/Shaders/defaultVertexShader.glsl",
			"../PowerAssets/Shaders/defaultFragmentShader.glsl" };
	};
}
