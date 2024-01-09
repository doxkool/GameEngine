#pragma once

#include "Core/Logger.h"

#include <GL/glew.h>

namespace Engine
{
	class Shader
	{
	public:
		Shader();
		~Shader();

		void Init(const char* vertexShaderFile, const char* fragmentShaderFile);

		std::string ReadShaderFile(const char* ShaderFile);

		void Activate();
		void Delete();

		GLuint ID;

	private:
		const char* m_vertexShaderFile;
		const char* m_fragmentShaderFile;
	};
}