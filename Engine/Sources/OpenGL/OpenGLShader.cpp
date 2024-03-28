#include "OpenGL/OpenGLShader.h"


namespace Engine
{
	Ref<OpenGLShader> OpenGLShader::Create(const char* vertexShaderFile, const char* fragmentShaderFile)
	{
		return CreateRef<OpenGLShader>(vertexShaderFile, fragmentShaderFile);
	}

	std::string OpenGLShader::ReadShaderFile(const char* ShaderFile)
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
			LOG_ERROR("ERROR::SHADER::COULD_NOT_OPEN_FILE: {}", ShaderFile);
		}

		in_file.close();

		return src;
	}

	OpenGLShader::OpenGLShader(const char* vertexShaderFile, const char* fragmentShaderFile)
	{
		if (vertexShaderFile != NULL && fragmentShaderFile != NULL)
		{
			std::string str_src;
			const GLchar* src;

			// build and compile our shader program
			// ------------------------------------
			// vertex shader
			unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
			str_src = ReadShaderFile(vertexShaderFile);
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
				LOG_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n");
				LOG_ERROR(infoLog);
			}
			else
			{
				LOG_TRACE("Shader compilation succeded: {}", vertexShaderFile);
			}
			// fragment shader
			unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
			str_src = ReadShaderFile(fragmentShaderFile);
			src = str_src.c_str();
			glShaderSource(fragmentShader, 1, &src, NULL);
			glCompileShader(fragmentShader);
			// check for shader compile errors
			glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
				LOG_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n");
				LOG_ERROR(infoLog);
			}
			else
			{
				LOG_TRACE("Shader compilation succeded: {}", fragmentShaderFile);
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
				LOG_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n");
				LOG_ERROR(infoLog);
			}
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);
		}
	}

	OpenGLShader::~OpenGLShader()
	{
		Delete();
	}

	//void OpenGLShader::LoadShader(const char* vertexShaderFile, const char* fragmentShaderFile)
	//{
	//
	//}

	// Activates the Shader Program
	void OpenGLShader::Activate()
	{
		glUseProgram(ID);
	}

	// Deletes the Shader Program
	void OpenGLShader::Delete()
	{
		//LOG_TRACE("Deleting shader program...");
		glDeleteProgram(ID);
	}

	void OpenGLShader::set1i(GLint value, const GLchar* name)
	{
		glUniform1i(glGetUniformLocation(ID, name), value);
	}

	void OpenGLShader::set1f(GLfloat value, const GLchar* name)
	{
		glUniform1f(glGetUniformLocation(ID, name), value);
	}

	void OpenGLShader::setVec2f(glm::fvec2 value, const GLchar* name)
	{
		glUniform2fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(value));
	}

	void OpenGLShader::setVec3f(glm::fvec3 value, const GLchar* name)
	{
		glUniform3fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(value));
	}

	void OpenGLShader::setVec4f(glm::fvec4 value, const GLchar* name)
	{
		glUniform4fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(value));
	}

	void OpenGLShader::setMat3fv(glm::mat3 value, const GLchar* name, GLboolean transpose)
	{
		glUniformMatrix3fv(glGetUniformLocation(ID, name), 1, transpose, glm::value_ptr(value));
	}

	void OpenGLShader::setMat4fv(glm::mat4 value, const GLchar* name, GLboolean transpose)
	{
		glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, transpose, glm::value_ptr(value));
	}

	int OpenGLShader::GetID() const
	{
		return ID;
	}
}