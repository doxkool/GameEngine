#include "Platforms/OpenGL/OpenGL_Shader.h"

namespace Engine
{
	Ref<Shader> Shader::CreateVertexShader(const std::string& filepath)
	{
		return CreateRef<OpenGL_Shader>(GL_VERTEX_SHADER, filepath);
	}
	Ref<Shader> Shader::CreateFragmentShader(const std::string& filepath)
	{
		return CreateRef<OpenGL_Shader>(GL_FRAGMENT_SHADER, filepath);
	}
}