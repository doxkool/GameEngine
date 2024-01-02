#pragma once

#include "Platforms/OpenGL/OpenGL_API.h"

#include "Renderer/Shader.h"

namespace Engine
{
	class Renderer
	{
		public:
			Renderer();
			virtual ~Renderer();

			void LoadShaders(const char* vertexSourceFile, const char* fragmentSourceFile);

		private:
			Shader Shaders;
			unsigned int m_ShaderProgram;

			const char* m_vertexSourceFile;
			const char* m_fragmentSourceFile;

	};
}