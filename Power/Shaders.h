#pragma once

#include "pch.h"
#include "PowerUtil.h"
#include "ShadersImpl.h"

namespace ow {
	class POW_API Shaders {
	public:
		Shaders();
		Shaders(const std::string& vShaderFile, const std::string& fragmentShaderFile);
		void LoadShaders(const std::string& vShaderFile, const std::string& fragmentShaderFile);

		void Bind();
		void setIntUniform(const std::string& uniformName, const std::vector<int>& values);
		void setIntUniform(const std::string& uniformName, int value);

	private:
		std::unique_ptr<ShadersImpl> implementation;
	};
}