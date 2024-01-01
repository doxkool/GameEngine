#include "Platforms/OpenGL/OpenGL_Shader.h"
#include "Core/Logger.h"

#include <fstream>

namespace Engine
{
	OpenGL_Shader::OpenGL_Shader(const GLenum type, const std::string& filepath)
		: m_FilePath(filepath)
	{
		//std::string shader_source = this->loadShaderFile(filepath);

		GLuint Compiled_Shader = 0;
		
		Compiled_Shader = CreateShaderProgram(type);

		linkProgram(Compiled_Shader);
	}

	OpenGL_Shader::~OpenGL_Shader()
	{
		glDeleteProgram(m_RendererID);
	}

	std::string OpenGL_Shader::loadShaderFile()
	{
		std::string temp = "";
		std::string src = "";

		std::ifstream in_file;

		//Vertex
		in_file.open(m_FilePath);

		if (in_file.is_open())
		{
			while (std::getline(in_file, temp))
				src += temp + "\n";
		}
		else
		{
			LOG_E_ERROR("ERROR::SHADER::COULD_NOT_OPEN_FILE: {}", m_FilePath);
			throw("ERROR OPENING SHADER FILE");
		}

		in_file.close();

		return src;
	}

	GLuint OpenGL_Shader::CreateShaderProgram(GLenum type)
	{
		char infoLog[512];
		GLint success;

		const char* fileName = m_FilePath.data();

		GLuint shader = glCreateShader(type);
		std::string str_src = this->loadShaderFile();
		const GLchar* src = str_src.c_str();
		glShaderSource(shader, 1, &src, NULL);
		glCompileShader(shader);

		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, NULL, infoLog);
			LOG_E_ERROR("ERROR::SHADER::COULD_NOT_COMPILE_SHADER: {}", fileName);
			LOG_E_ERROR(infoLog);
		}
		else {
			LOG_E_DEBUG("Shader loaded: {}", fileName);
		}

		return shader;
	}

	void OpenGL_Shader::linkProgram(GLuint shader)
	{
		char infoLog[512];
		GLint success;

		GLuint program = glCreateProgram();

		glAttachShader(program, shader);

		glLinkProgram(program);

		glGetProgramiv(program, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(program, 512, NULL, infoLog);
			LOG_E_ERROR("ERROR::SHADER::COULD_NOT_LINK_PROGRAM");
			LOG_E_ERROR(infoLog);
		}
		else {
			LOG_E_DEBUG("Shader compiled.");
		}

		m_RendererID = program;
	}
}