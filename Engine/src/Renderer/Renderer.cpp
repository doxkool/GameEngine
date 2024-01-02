#include "Renderer/Renderer.h"

namespace Engine
{
	
	Renderer::Renderer()
	{
	}

	Renderer::~Renderer()
	{
	}

	void Renderer::LoadShaders(const char* vertexSourceFile, const char* fragmentSourceFile)
	{
		m_ShaderProgram = Shaders.LoadShader(vertexSourceFile, fragmentSourceFile);
	}
}