#include "pch.h"
#include "Image.h"
#include "codeOpenGL/OpenGLImage.h"

namespace ow 
{
	Image::Image()
	{
#ifdef POW_OPENGL_STBI
		implementation = std::unique_ptr<ImageImpl>{ new OpenGLImage()};
#else
	#only_opengl_is_supported_so_far
#endif
	}

	Image::Image(const std::string& filePath)
	{
#ifdef POW_OPENGL_STBI
		implementation = std::unique_ptr<ImageImpl>{ new OpenGLImage(filePath) };
#else
		#only_opengl_is_supported_so_far
#endif
	}

	void Image::LoadImage(const std::string& filePath)
	{
		implementation->LoadImage(filePath);
	}

	bool Image::containsImage() const
	{
		return implementation->containsImage();
	}

	int Image::getWidth() const
	{
		return implementation->getWidth();
	}

	int Image::getHeight() const
	{
		return implementation->getHeight();
	}

	void Image::Bind()
	{
		implementation->Bind();
	}
}