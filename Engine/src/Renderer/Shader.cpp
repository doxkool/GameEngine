#include "Renderer/shader.h"


namespace Engine
{
	std::string Shader::ReadShaderFile(const char* ShaderFile)
	{
		std::string temp = "";
		std::string src = "";

		std::ifstream in_file;

		//Vertex
		in_file.open(ShaderFile);

		if (in_file.is_open())
		{
			while (std::getline(in_file, temp))
				src += temp + "\n";
		}
		else
		{
			LOG_E_ERROR("ERROR::SHADER::COULD_NOT_OPEN_FILE: {}", ShaderFile);
		}

		in_file.close();

		return src;
	}

	Shader::Shader()
	{
	}

	Shader::~Shader()
	{
	}

	void Shader::Init(const char* vertexShaderFile, const char* fragmentShaderFile)
	{
		m_vertexShaderFile = vertexShaderFile;
		m_fragmentShaderFile = fragmentShaderFile;

		std::string str_src;
		const GLchar* src;

		// build and compile our shader program
		// ------------------------------------
		// vertex shader
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		str_src = this->ReadShaderFile(m_vertexShaderFile);
		src = str_src.c_str();
		glShaderSource(vertexShader, 1, &src, NULL);
		glCompileShader(vertexShader);
		// check for shader compile errors
		int success;
		char infoLog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			LOG_E_DEBUG("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
			LOG_E_DEBUG(infoLog);
		}
		// fragment shader
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		str_src = this->ReadShaderFile(m_fragmentShaderFile);
		src = str_src.c_str();
		glShaderSource(fragmentShader, 1, &src, NULL);
		glCompileShader(fragmentShader);
		// check for shader compile errors
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			LOG_E_DEBUG("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n");
			LOG_E_DEBUG(infoLog);
		}
		// link shaders
		ID = glCreateProgram();
		glAttachShader(ID, vertexShader);
		glAttachShader(ID, fragmentShader);
		glLinkProgram(ID);
		// check for linking errors
		glGetProgramiv(ID, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(ID, 512, NULL, infoLog);
			LOG_E_DEBUG("ERROR::SHADER::PROGRAM::LINKING_FAILED\n");
			LOG_E_DEBUG(infoLog);
		}
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	// Activates the Shader Program
	void Shader::Activate()
	{
		glUseProgram(ID);
	}

	// Deletes the Shader Program
	void Shader::Delete()
	{
		LOG_E_TRACE("Deleting shader program...");
		glDeleteProgram(ID);
	}
}