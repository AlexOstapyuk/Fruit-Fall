#include "pch.h"
#include "OpenGLImage.h"

#include "glad/glad.h"
#include "stb_image.h"
#include "PowerUtil.h"

namespace ow {
	OpenGLImage::OpenGLImage()
	{

	}

	OpenGLImage::OpenGLImage(const std::string& filePath)
	{
		glGenTextures(1, &mImage);
		glBindTexture(GL_TEXTURE_2D, mImage);
		// set the texture wrapping/filtering options (on the currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		unsigned char* data{ nullptr };
		int nrChannels{ 0 };
		stbi_set_flip_vertically_on_load(true);
		data = stbi_load(filePath.c_str(), &mWidth, &mHeight, &nrChannels, 0);
		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			POW_ERROR("Failed to load texture");
		}
		stbi_image_free(data);


	}

	void OpenGLImage::LoadImage(const std::string& filePath)
	{
		if (mImage) {
			glDeleteTextures(1, &mImage);
		}

		glGenTextures(1, &mImage);
		glBindTexture(GL_TEXTURE_2D, mImage);
		// set the texture wrapping/filtering options (on the currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		unsigned char* data{ nullptr };
		int nrChannels{ 0 };
		stbi_set_flip_vertically_on_load(true);
		data = stbi_load(filePath.c_str(), &mWidth, &mHeight, &nrChannels, 0);
		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, mWidth, mHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			POW_ERROR("Failed to load texture");
		}
		stbi_image_free(data);
	}

	bool OpenGLImage::containsImage() const
	{
		return mImage ? true : false;
	}

	int OpenGLImage::getWidth() const
	{
		return mWidth;
	}

	int OpenGLImage::getHeight() const
	{
		return mHeight;
	}

	void OpenGLImage::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, mImage);
	}

	/*void OpenGLImage::deleteImage()
	{
		glDeleteTextures(1, &mImage);
	}*/

	OpenGLImage::~OpenGLImage()
	{
		glDeleteTextures(1, &mImage);
	}
}


