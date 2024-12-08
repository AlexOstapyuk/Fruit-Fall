#include "pch.h"

#include "OpenGLShaders.h"
#include "glad/glad.h"
#include "PowerUtil.h"

namespace ow {
	OpenGLShaders::OpenGLShaders()
	{
	}

	OpenGLShaders::OpenGLShaders(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
	{
		std::string vertexShaderCode{ readFile(vertexShaderFile) };
		const char* cVertexCode{ vertexShaderCode.c_str()};
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &cVertexCode, NULL);
		glCompileShader(vertexShader);

		int  success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

		if (!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			POW_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
		}
		


		std::string fragmentShaderCode{ readFile(fragmentShaderFile) };
		const char* cFragmentCode{ fragmentShaderCode.c_str() };
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &cFragmentCode, NULL);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			POW_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
		}


		mShaders = glCreateProgram();
		glAttachShader(mShaders, vertexShader);
		glAttachShader(mShaders, fragmentShader);
		glLinkProgram(mShaders);

		glGetProgramiv(mShaders, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(mShaders, 512, NULL, infoLog);
			POW_ERROR("ERROR::SHADER::PROGRAM_LINKING_FAILED\n" << infoLog);
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void OpenGLShaders::LoadShaders(const std::string& vertexShaderFile, const std::string& fragmentShaderFile)
	{
		if (mShaders != 0) {
			glDeleteProgram(mShaders);
		}

		std::string vertexShaderCode{ readFile(vertexShaderFile) };
		const char* cVertexCode{ vertexShaderCode.c_str() };
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &cVertexCode, NULL);
		glCompileShader(vertexShader);

		int  success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

		if (!success) {
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			POW_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
		}



		std::string fragmentShaderCode{ readFile(fragmentShaderFile) };
		const char* cFragmentCode{ fragmentShaderCode.c_str() };
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &cFragmentCode, NULL);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			POW_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
		}


		mShaders = glCreateProgram();
		glAttachShader(mShaders, vertexShader);
		glAttachShader(mShaders, fragmentShader);
		glLinkProgram(mShaders);

		glGetProgramiv(mShaders, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(mShaders, 512, NULL, infoLog);
			POW_ERROR("ERROR::SHADER::PROGRAM_LINKING_FAILED\n" << infoLog);
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void OpenGLShaders::Bind()
	{
		glUseProgram(mShaders);
	}

	void OpenGLShaders::setIntUniform(const std::string& uniformName, const std::vector<int>& values)
	{
		glUseProgram(mShaders);

		int location{ glGetUniformLocation(mShaders, uniformName.c_str()) };
		switch (values.size())
		{
		case 1:
			glUniform1i(location, values[0]);
			break;
		case 2:
			glUniform2i(location, values[0], values[1]);
			break;
		case 3:
			glUniform3i(location, values[0], values[1], values[2]);
			break;
		case 4:
			glUniform4i(location, values[0], values[1], values[2], values[3]);
			break;
		default:
			POW_ERROR("Integer uniforms of this size cannot be used")
		}

	}

	void OpenGLShaders::setIntUniform(const std::string& uniformName, int value)
	{
		glUseProgram(mShaders);

		int location{ glGetUniformLocation(mShaders, uniformName.c_str()) };
		glUniform1i(location, value);
	}

	OpenGLShaders::~OpenGLShaders()
	{
		if (mShaders != 0) {
			glDeleteProgram(mShaders);
		}
	}

	std::string OpenGLShaders::readFile(const std::string fileName) const
	{
		std::ifstream input{ fileName };

		assert(input); //check if file opening was good(true)

		std::string res;
		std::string line;

		while (input) {
			line.clear();
			getline(input, line);
			res += line;
			res += "\n";
		}

		input.close();

		return res;
	}
}
