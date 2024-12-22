#pragma once

#include "pch.h"
#include "PowerUtil.h"
#include "ImageImpl.h"

namespace ow {
	class POW_API Image {
	public:
		Image();
		Image(const std::string& filePath);
		void LoadImage(const std::string& filePath);

		bool containsImage() const;
		int getWidth() const;
		int getHeight() const;

		//void deleteImage();

	
		void Bind(); //should be private
private:
		std::unique_ptr<ImageImpl> implementation;

		friend class Renderer;
	};
}
