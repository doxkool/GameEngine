#include "Renderer/Shader.h"

namespace Engine
{
	// Constructor that build the Shader Program from 2 different shaders
	Shader::Shader(const char* vertexFile, const char* fragmentFile)
		: m_VertexFile(vertexFile), m_FragmentFile(fragmentFile)
	{
		OpenGL_Shader GL_Shader(m_VertexFile, m_FragmentFile);

		GL_ShaderProgram = GL_Shader.Get_ShaderProgram();
	}

	// Activates the Shader Program
	void Shader::Activate()
	{
		
	}

	// Deletes the Shader Program
	void Shader::Delete()
	{
		
	}
}