#pragma once

#include "../ShadersImpl.h"

namespace ow {
	class OpenGLShaders : public ShadersImpl{
	public:
		OpenGLShaders();
		OpenGLShaders(const std::string& vertexShaderFile, const std::string& fragmentShaderFile);
		virtual void LoadShaders(const std::string& vertexShaderFile, const std::string& fragmentShaderFile) override;
		virtual void Bind() override;
		virtual void setIntUniform(const std::string& uniformName, const std::vector<int>& values) override;
		virtual void setIntUniform(const std::string& uniformName, int value) override;

		~OpenGLShaders();

	private:
		unsigned int mShaders{ 0 };
		std::string readFile(const std::string fileName) const;

	};
}