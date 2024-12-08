#pragma once

#include "pch.h"

namespace ow {
	class ShadersImpl {
	public:
		virtual void LoadShaders(const std::string& vertexShaderFile, const std::string& fragmentShaderFile) = 0;
		virtual void Bind() = 0;
		virtual void setIntUniform(const std::string& uniformName, const std::vector<int>& values) = 0;
		virtual void setIntUniform(const std::string& uniformName, int value) = 0;

		virtual ~ShadersImpl() {};
	};
}