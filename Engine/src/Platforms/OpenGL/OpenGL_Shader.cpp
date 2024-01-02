#include "Platforms/OpenGL/OpenGL_Shader.h"
#include "Core/Logger.h"

#include <fstream>

namespace Engine
{
	OpenGL_Shader::OpenGL_Shader(const char* vertexFile, const char* fragmentFile)
		: m_VertexFile(vertexFile), m_FragmentFile(fragmentFile)
	{
		// TODO : Add code to load shader files
	}

	unsigned int OpenGL_Shader::Get_ShaderProgram()
	{
		return m_ShaderProgram;
	}

	OpenGL_Shader::~OpenGL_Shader()
	{
		
	}
}