#pragma once

#include "pch.h"

namespace ow {
	class ImageImpl {
	public:
		virtual void LoadImage(const std::string& filePath) = 0;

		virtual bool containsImage() const = 0;
		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;

		virtual void Bind() = 0;

		virtual ~ImageImpl() {};
	};
}
