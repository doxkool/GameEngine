#pragma once

#include "Platforms/OpenGL/OpenGL_API.h"

namespace Engine
{
	class OpenGL_Shader
	{
		public:
			// Reference ID of the Shader Program
			GLuint ID;

			OpenGL_Shader(const char* vertexFile, const char* fragmentFile);
			virtual ~OpenGL_Shader();

			unsigned int Get_ShaderProgram();

			void compileErrors(unsigned int shader, GLenum type);


		private:
			const char* m_VertexFile;
			const char* m_FragmentFile;

			unsigned int m_ShaderProgram;
	};
}