#include "Platforms/OpenGL/OpenGL_Shader.h"
#include "Core/Logger.h"

#include <fstream>

namespace Engine
{
	OpenGL_Shader::OpenGL_Shader(const char* vertexSource, const char* fragmentSource)
	{
		// Create Vertex Shader Object and get its reference
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
		// Attach Vertex Shader source to the Vertex Shader Object
		glShaderSource(vertexShader, 1, &vertexSource, NULL);
		// Compile the Vertex Shader into machine code
		glCompileShader(vertexShader);
		// Checks if Shader compiled succesfully
		compileErrors(vertexShader, GL_VERTEX_SHADER);

		// Create Fragment Shader Object and get its reference
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		// Attach Fragment Shader source to the Fragment Shader Object
		glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
		// Compile the Vertex Shader into machine code
		glCompileShader(fragmentShader);
		// Checks if Shader compiled succesfully
		compileErrors(fragmentShader, GL_FRAGMENT_SHADER);

		// Create Shader Program Object and get its reference
		ID = glCreateProgram();
		// Attach the Vertex and Fragment Shaders to the Shader Program
		glAttachShader(ID, vertexShader);
		glAttachShader(ID, fragmentShader);
		// Wrap-up/Link all the shaders together into the Shader Program
		glLinkProgram(ID);
		// Checks if Shaders linked succesfully
		compileErrors(ID, GL_PROGRAM);

		// Delete the now useless Vertex and Fragment Shader objects
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	// Checks if the different Shaders have compiled properly
	void OpenGL_Shader::compileErrors(unsigned int shader, GLenum type)
	{
		// Stores status of compilation
		GLint hasCompiled;
		// Character array to store error message in
		char infoLog[1024];
		if (type != GL_PROGRAM)
		{
			glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
			if (hasCompiled == GL_FALSE)
			{
				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
				LOG_E_ERROR("ERROR::SHADER::COULD_NOT_COMPILE_SHADER: {}", shader);
				LOG_E_ERROR(infoLog);
			}
		}
		else
		{
			glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);
			if (hasCompiled == GL_FALSE)
			{
				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
				LOG_E_ERROR("ERROR::SHADER::COULD_NOT_LINK_PROGRAM");
				LOG_E_ERROR(infoLog);
			}
		}
	}

	unsigned int OpenGL_Shader::Get_ShaderProgram()
	{
		return m_ShaderProgram;
	}

	OpenGL_Shader::~OpenGL_Shader()
	{
		
	}
}