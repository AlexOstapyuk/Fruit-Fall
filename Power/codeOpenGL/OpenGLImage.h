#pragma once

#include "../ImageImpl.h"

namespace ow {
	class OpenGLImage : public ImageImpl{
	public:
		OpenGLImage();
		OpenGLImage(const std::string& filePath);
		virtual void LoadImage(const std::string& filePath) override;

		virtual bool containsImage() const override;
		virtual int getWidth() const override;
		virtual int getHeight() const override;

		virtual void Bind() override;

		//virtual void deleteImage() override;

		~OpenGLImage();

	private:
		unsigned mImage{ 0 };
		int mHeight{ 0 };
		int mWidth{ 0 };
	};
}