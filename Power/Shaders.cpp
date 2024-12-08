#include "pch.h"
#include "Shaders.h"
#include "codeOpenGL/OpenGLShaders.h"

namespace ow {

	Shaders::Shaders()
	{
#ifdef POW_OPENGL_STBI
		implementation = std::unique_ptr<ShadersImpl>{ new OpenGLShaders() };
#else
		#only_opengl_is_supported_so_far
#endif
	}

	Shaders::Shaders(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
	{
#ifdef POW_OPENGL_STBI
		implementation = std::unique_ptr<ShadersImpl>{ new OpenGLShaders(vertexShaderFile, fragmentShaderFile) };
#else
		#only_opengl_is_supported_so_far
#endif
	}

	void Shaders::LoadShaders(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
	{
		implementation->LoadShaders(vertexShaderFile, fragmentShaderFile);
	}

	void Shaders::Bind()
	{
		implementation->Bind();
	}

	void Shaders::setIntUniform(const std::string& uniformName, const std::vector<int>& values)
	{
		implementation->setIntUniform(uniformName, values);
	}

	void Shaders::setIntUniform(const std::string& uniformName, int value)
	{
		implementation->setIntUniform(uniformName, value);
	}

	
}